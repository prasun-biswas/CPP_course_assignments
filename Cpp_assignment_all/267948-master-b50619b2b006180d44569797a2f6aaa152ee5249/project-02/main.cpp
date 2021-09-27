
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>


#include "splitter.h"
#include "read_and_store.h"
#include "query.h"


typedef void (*no_arg_pfunctions)(const map <string, map <string, map<string, double>>>& read_map);
typedef void (*one_arg_pfunctions)(const map <string, map <string, map<string, double>>>& read_map, const string&);
typedef void (*two_arg_pfunctions)(const map <string, map <string, map<string, double>>>& read_map,const string&, const string&);



int main(){

    string input;
    vector <string> input_vector;
    Splitter ui;

    map<string, no_arg_pfunctions> no_arg_map;
    map<string, one_arg_pfunctions> one_arg_map;

    no_arg_pfunctions no_arg_pfunct;
    one_arg_pfunctions one_arg_pfunct;



        no_arg_map["chains"] = chains;
        one_arg_map["stores"] = stores;
        one_arg_map["cheapest"] = cheapest;
        //two_arg_map["selection"] = selection;


 map<string,map<string,map<string,double>>> read_map= read_and_store_map("products.txt");
// for(auto chain=read_map.begin();chain !=read_map.end();++chain){
//     for(auto store=chain->second.begin();store!=chain->second.end();++store){
//         for(auto product=store->second.begin();product!=store->second.end();++product){
//             cout<<chain->first<<" stores "<<store->first<<" product "<<product->first<<" price "<<product->second<<endl;
//         }

//     }
// }


 while (true) {
     // print prompt text for taking input
     cout<<"product search> ";
//takes input using getline method to input string declared above
     getline(cin,input);
     ui.clear_vec();
     ui.set_split_string(input);
     ui.set_separator(' ');
     ui.split_insert_vec();
     input_vector=ui.fields_vec();

     //run switch-case loop to find field match for valid query
     switch (ui.field_counter()) {
     case 0:{
     cout<<"Error: Not enough commands!"<<endl;
     break;
     }
     case 1:{
     auto i=no_arg_map.find(input_vector[0]);
     if(i!=no_arg_map.end()){
         no_arg_pfunct=no_arg_map[input_vector[0]];
(*no_arg_pfunct)(read_map);

     }else if (input_vector[0]=="quit") {
         quit();
     }
     else if (check_command(input_vector[0])) {
         cout<<"Error: command format wrong.\n";

     }
     else {
         cout<<"Error: command not found! \n";
     }

     }//case:1 ends here

         break;

     case 2:{

         auto i = one_arg_map.find(input_vector[0]);
         if(i!=one_arg_map.end()){
one_arg_pfunct=one_arg_map[input_vector[0]];
(*one_arg_pfunct)(read_map, input_vector[1]);
         } else if (check_command(input_vector[0])) {
             cout<<"Error: command format wrong.\n";

         }else {
             cout<<"Error: command not found! \n";
         }


     }//case:2 ends here

         break;
     case 3:{
         if (input_vector[0]=="selection"){
            selection(read_map,input_vector[1],input_vector[2]);
         }else if (check_command(input_vector[0])) {
             cout<<"Error: command format wrong.\n";

         }else {
             cout<<"Error: command not found! \n";
         }

     }// case:3 ends here

         break;

     default:{
         if (check_command(input_vector[0])) {
                         cout << "Error: command format wrong.\n";

                     } else {
                         cout << "Error: command not found! \n";

                     }




     }// checking for default

         break;


     }//switch ends here




 }// while(true) loop ends here


    return 0;
}//main() ends here
