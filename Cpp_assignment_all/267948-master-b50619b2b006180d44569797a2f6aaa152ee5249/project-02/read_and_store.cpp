#include "read_and_store.h"
#include "splitter.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>



//Read_and_store::Read_and_store()
//{

//}

map <string, map<string, map<string, double>>> read_and_store_map(const string & file_name){

    size_t char_check=0;
    bool product_update;
    string temp_String;
    map <string, double> prd_prc;
    map <string, map<string,double>> str_prd_prc;
    map <string, map<string, map<string, double>>> chn_str_prd_prc;


ifstream file;

vector <string> readvector;

Splitter temp;
string line;

file.open(file_name);
if(file.is_open()){
    while (getline(file,line)) {
        readvector.push_back(line);

        temp.clear_vec();
        prd_prc.clear();
        str_prd_prc.clear();
        product_update=false;

        temp.set_split_string(line);
        temp.split_insert_vec();
        readvector=temp.fields_vec();

        size_t sp= count(line.begin(),line.end(),';');
        size_t ef= line.find(' ');

        if(sp!=3){
            cout<<"1 Error: the input file can not be read";
            exit(0);
        }
        if(temp.is_field_empty()){
            cout<<"2 Error: the input file can not be read";
            exit(0);
        }
        if(ef!=string::npos){
            cout<<"3 Error: the input file can not be read";
            exit(0);

        }

//check for chain in map
        
        auto chain_check = chn_str_prd_prc.find(readvector[0]);
        if(chain_check==chn_str_prd_prc.end()){
            chn_str_prd_prc[readvector[0]]=str_prd_prc;

        }
//check store in chain
        
        auto store_check = chn_str_prd_prc.at(readvector[0]).find(readvector[1]);
        if (store_check==chn_str_prd_prc.at(readvector[0]).end()){
            chn_str_prd_prc.at(readvector[0])[readvector[1]]=prd_prc;

            auto chain=chn_str_prd_prc.begin();
            for( chain;
                chain!=chn_str_prd_prc.end();
                ++chain){
                //cout<<chain->first <<endl;
                auto store=chn_str_prd_prc.at(chain->first).begin();
                for(store;store!=chn_str_prd_prc.at(chain->first).end();++store){
                    //cout<<store->first <<endl;
                }
            }
        }

//check product in store
        auto product_check=chn_str_prd_prc.at(readvector[0]).at(readvector[1]).find(readvector[2]);
        if(product_check==chn_str_prd_prc.at(readvector[0]).at(readvector[1]).end()){

            double price=stod(readvector[3],&char_check);
            temp_String=readvector[3].substr(char_check);
           if(temp_String.empty()){
            chn_str_prd_prc.at(readvector[0]).at(readvector[1])[readvector[2]] =price;
           }

      }

//        for(auto chain=chn_str_prd_prc.begin();chain !=chn_str_prd_prc.end();++chain){
//            for(auto store=chain->second.begin();store!=chain->second.end();++store){
//                for(auto product=store->second.begin();product!=store->second.end();++product){
//                    cout<<chain->first<<" stores "<<store->first<<" product "<<product->first<<" price "<<product->second<<endl;
//                }

//            }
//        }


    }
    file.close();



}else {
    cout << "\nError: the input file can not be read";
    exit(0);
}



return chn_str_prd_prc;



}
