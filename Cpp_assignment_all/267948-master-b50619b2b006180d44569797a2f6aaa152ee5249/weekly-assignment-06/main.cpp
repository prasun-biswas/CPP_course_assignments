#include <iostream>
#include <map>

using namespace std;


int count_names(map<string, string>::const_iterator iter,
                map<string, string>::const_iterator end,
                char initial_letter) {
    if ( iter == end ) {
        return 0;

    } else if ( iter->first.at(0) != initial_letter ) {
        ++iter;
        return count_names(iter, end, initial_letter);

    } else {
        ++iter;
        return 1 + count_names(iter, end, initial_letter);
    }
}


int main() {
    map<string, string> phonebook = {
        { "Jim",    "00000000000" },
        { "Donald", "11111111111" },
        { "Jack",   "22222222222" },
        { "Doris",  "33333333333" },
        { "Jones",  "44444444444" },
    };

    cout << count_names(phonebook.begin(), phonebook.end(), 'J' ) << endl;
}
