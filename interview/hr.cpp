#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;


int main() {
ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long N;
    long long n;
    cin >> N;
    multiset<long long> in;
    while(N--) {
        cin >> n;
        in.insert(llabs(n));
    }

    long long prev=0;
    long long m = numeric_limits<long long>::max();

    for(auto i = in.begin(); i != in.end();++i) {
        if(i == in.begin()) {
            prev = *i;
            continue;
        }
        long long abs_diff = *i - prev;
        if(abs_diff < m) {
            m = abs_diff;
        }
    }
    cout << m << endl;               
    return 0;
}

