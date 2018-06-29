#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {100,100, 50, 40,40,20,10};
    cout << binary_search(v.rbegin(), v.rend(), 40) << endl;
    vector <int> v1 = {100,100,50,40};
    cout << binary_search(v1.rbegin(), v1.rend(), 100) << endl;
    vector <int> v2 = {100,100,50,40};
    cout << binary_search(v2.rbegin(), v2.rend(), 40) << endl;
    return 0;
}

