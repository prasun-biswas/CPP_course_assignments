#include "splitter.h"
#include <iostream>
#include <vector>
#include <string>

Splitter::Splitter()
{
//constructor: private variables are initiatied at start of program.
    separator_=';';
    field_count_=0;
    field_empty_=false;
    split_string_="";
}


void Splitter::set_separator(const char & separator){    //different separator can be used for reuse of separator class

    separator_=separator;
}
void Splitter::set_split_string(const string &line){ // set line to split after reading from file
    split_string_=line;
}
bool Splitter::is_field_empty() const{ // return bool value of field_empty_

    return field_empty_;
}
int Splitter::field_counter() const{ // count fields of split_string_
   return field_count_;
}
vector<string> Splitter::fields_vec() const{
    return split_string_vec_;
}
void Splitter::clear_vec(){ // make sure that nothing stored in  the vector
    split_string_vec_.clear();
}
void Splitter::split_insert_vec(){ // split and insert fields into vector

    string temp_String;
    field_count_=0;
    size_t position=0;
    size_t is_separator=split_string_.find(separator_,position);

    temp_String=split_string_.substr(position,(is_separator-position));
    while (is_separator!=string::npos) {
        if(!temp_String.empty()){
            split_string_vec_.push_back(temp_String);
            field_count_+=1;

        } else
            field_empty_=true;
            position=(is_separator+1);
            is_separator=split_string_.find(separator_,position);
            temp_String=split_string_.substr(position,(is_separator-position));

    }
    if(!temp_String.empty()){
        split_string_vec_.push_back(temp_String);
        field_count_+=1;
    }


}










