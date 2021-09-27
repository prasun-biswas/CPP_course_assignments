#include <iostream>
#include "stack.hh"

using namespace std;


int main() {
    Stack test_stack;

    test_stack.print();

    test_stack.push_front(1);
    test_stack.push_front(2);
    test_stack.push_front(3);

    test_stack.print();

    test_stack.reverse();

    test_stack.print();

    int number;
    while ( test_stack.pop_front(number) ) {
        cout << number << endl;
    }
}
