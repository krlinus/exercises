#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
    if (n < 3) {
        return -1;
    }
    vector<int> leastOnRight(n);
    vector<int> greatestOnLeft(n);
    
    int greatest=INT_MIN;
    for(int i=1;i<n;++i) {
        if(arr[i] >= greatest) {
             greatest = greatestOnLeft[i] = arr[i];
        } else {
            greatestOnLeft[i] = greatestOnLeft[i-1];
        }
    }
    
    int least=INT_MAX;
    for(int i=n-2;i>=0;i--) {
        if(arr[i] <= least) {
            least = leastOnRight[i] = arr[i];
        } else {
            leastOnRight[i] = leastOnRight[i+1];
        }
    }
    
    for(int i=1;i<n-1;++i) {
        if(arr[i] >= greatestOnLeft[i] && arr[i] <= leastOnRight[i]) {
            return arr[i];
        }
    }
    return -1;
}
