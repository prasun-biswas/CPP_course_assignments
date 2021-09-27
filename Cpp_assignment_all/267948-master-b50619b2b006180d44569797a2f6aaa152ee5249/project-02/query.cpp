#include "query.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

 map <string,int> query_map= {{"quit",0},{"chains",1},{"stores",2},{"cheapest",3},{"selection",4}};

// void quit(const map<string, map<string, map<string, double> > > &read_map){
//     auto copy_map = read_map;
//     exit(0);

// }
 void quit(){
     exit(0);

 }
 void chains(const map<string, map<string, map<string, double> > > &read_map){
     for(auto chain=read_map.begin();chain!=read_map.end();++chain){
         cout<<chain->first <<endl;
     }
 }// chain search ends here.

 void stores(const map<string, map<string, map<string, double> > > &read_map, const string &chain){
     auto chain_check = read_map.find(chain);
     if (chain_check != read_map.end()){
         for(auto store= read_map.at(chain).begin();store != read_map.at(chain).end();++store){
             cout<<store->first<< endl;
         }
     } else{
         cout<<"Error: Market chain unavailable. \n";
     }
 }// store location of chains search ends here.

 void cheapest(const map<string, map<string, map<string, double> > > &read_map, const string& product_name){

     double cheapest_price =numeric_limits<double>::infinity();
     //cout<<"searching for cheapest:"<<product_name<<endl;

     multimap <string, string> store_list;

     //check inside the map through using loops

     for(auto chain=read_map.begin();chain!=read_map.end();++chain){
         //cout<<"searching in chain for:"<<product_name<<endl;
         for(auto store=chain->second.begin();store !=chain->second.end();++store){
//             cout<<"searching in store for:"<<product_name<<endl;

             for(auto product=store->second.begin();product!=store->second.end();++product){
                 //<<"searchin in store for"<< product_name<<endl;
                if(product->first==product_name && product->second<cheapest_price){
                    //cout<<"searching for product for"<<product->first<<endl;
                    cheapest_price=product->second;
                    store_list.clear();
                    store_list.insert(make_pair(chain->first, store->first));
                } else if(product->first==product_name && product->second==cheapest_price){
                    store_list.insert(make_pair(chain->first, store->first));
                }

         }

         }//second for loop inside store locations
     }//first for loop for chain names
      //check if the product is available in any store
        if (store_list.empty()) {
            cout << "This product is not available anywhere.\n";
            return;
        }
        cout << fixed << setprecision(2)
               << cheapest_price << endl;

          for (auto store = store_list.begin();
               store != store_list.end(); ++store) {
              cout << store->first << " ";
              cout << store->second << endl;
          }


 }






void selection(const map<string, map<string, map<string, double> > > &read_map, const string &chain, const string &store){
    // for(auto chain=read_map.begin();chain !=read_map.end();++chain){
    //     for(auto store=chain->second.begin();store!=chain->second.end();++store){
    //         for(auto product=store->second.begin();product!=store->second.end();++product){
    //             cout<<chain->first<<" stores "<<store->first<<" product "<<product->first<<" price "<<product->second<<endl;
    //         }

    //     }
    // }

    auto chain_valid =read_map.find(chain);
    if(chain_valid!=read_map.end()){
        auto store_valid=read_map.at(chain).find(store);
        if(store_valid!=read_map.at(chain).end()){
//            auto product=store_valid->second;
            for(auto product=store_valid->second.begin();product!=store_valid->second.end();++product){
                cout<<product->first<<" "<<setprecision(2)<<product->second<<endl;
            }
        }else cout << "Error: store not found.\n";
    } else cout << "Error: chain not found.\n";

cout<<"searching selections in chain and store";
}



 bool check_command(const string &command){
     auto command_check =query_map.find(command);
     if(command_check != query_map.end()){
         return true;
     } else
         return false;
 }// user input command ends here.
