#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Students {
    string name;
    unsigned int opnum;
};


bool student comparator (const Student & left, const Student & right) {
    return left.name <right.name;
}


bool student address comparator (const Student * left,
                                 const Student * right) {
    return left-> opnum <right-> opnum;
}


int main () {





}
