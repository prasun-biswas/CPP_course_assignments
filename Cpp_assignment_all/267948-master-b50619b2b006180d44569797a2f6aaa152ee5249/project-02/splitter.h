#ifndef SPLITTER_H
#define SPLITTER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Splitter
{
public:
    Splitter();
    int field_counter() const;
    vector<string> fields_vec() const;
    void clear_vec();
    bool is_field_empty() const;
    void split_insert_vec();
    void set_separator(const char & separator);
    void set_split_string(const string & line);

 private:
    char separator_;
    int field_count_;
    bool field_empty_;
    string split_string_;
   vector<string> split_string_vec_;

};

#endif // SPLITTER_H
