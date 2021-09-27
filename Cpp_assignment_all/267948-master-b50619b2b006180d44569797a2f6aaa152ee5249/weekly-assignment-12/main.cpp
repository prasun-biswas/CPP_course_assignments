#include <iostream>

     using namespace std;

     int main () {
         int number1;
         int number2 = 111;
         int * pointer1 = new int;
         int * pointer2 = new int (222);

         cout << number1 << ""
              << number2 << ""
              << * pointer1 << ""
              << * pointer2 << endl;

         delete pointer1;

         * pointer1 = 333;
     }
