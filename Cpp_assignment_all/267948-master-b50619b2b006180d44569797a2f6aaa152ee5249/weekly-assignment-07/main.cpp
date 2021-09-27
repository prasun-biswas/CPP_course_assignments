#include <iostream>
#include <string>

using namespace std;
bool is_palindrome(const string& str) {
    unsigned int ln=str.size();
    if(ln<2){
        cout<<"palindrome"<<endl;
        return true;
    }
    else if (str.at(0)!=str.at(ln-1)) {
        cout<<"not a pal"<<endl;

        return false;
    }
    string new_str=str.substr(1,str.length()-2);
    return is_palindrome(new_str);

    }



int main(){
string st="abcdefgh";
string st1="abcddcba";
is_palindrome(st);
is_palindrome(st1);
return 0;

}
