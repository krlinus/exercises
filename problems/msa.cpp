#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_msa(int inp[], int sz) {
    if(sz == 0) return 0;
    if(sz == 1) return inp[0];
    if(sz == 2) return max(inp[0],inp[1]);
    int *dp = new int[sz];
    for(int i=0;i<sz;++i) dp[i]=-1;
    dp[0]=inp[0];
    dp[1]=max(inp[0],inp[1]);
    for(int i=2;i<sz;++i) {
        dp[i] = max(dp[i-2]+inp[i],dp[i-1]);
        cerr <<dp[i]<<" ";
    }
    cerr << endl;
    return dp[sz-1];
}

int main() {
    vector<int> arr;
    int t;
    do {
        cin >> t;
        if(t> 0) {
            arr.push_back(t);
        }
    }while(t >= 0);
    cout << get_msa(&arr[0], arr.size()) << endl;
    return 0;
}
