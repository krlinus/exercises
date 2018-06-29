#include <map>
#include <string>
#include <iostream>
using std::string;
using std::map;
using std::cin;
using std::cout;
using std:: endl;

int main() {
    string inp;
    map<string,int> counts;
    while(std::getline(cin, inp)) {
        if (inp.length() > 0)
        counts[inp]++;
    }
    for(map<string,int>::iterator i=counts.begin();i != counts.end();++i) {
        cout << i->second << " " << i->first << endl;
    }
    return 0;
}

