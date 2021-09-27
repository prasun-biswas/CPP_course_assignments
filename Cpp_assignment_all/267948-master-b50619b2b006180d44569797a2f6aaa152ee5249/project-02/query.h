#ifndef QUERY_H
#define QUERY_H



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "read_and_store.h"

using namespace std;

//map <string,int> query_map;


void quit();
void chains(const map<string, map<string, map<string,double>>> & read_map);
void stores(const map<string, map<string, map<string,double>>> & read_map, const string & chain);
void cheapest(const map<string, map<string, map<string,double>>> & read_map, const string & product_name);
void selection(const map <string, map <string, map <string,double>>>& read_map,const string& chain, const string& store);

bool check_command(const string & command);


#endif // QUERY_H
