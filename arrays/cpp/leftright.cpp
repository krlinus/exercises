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

    int least=INT_MAX;
    for(int i=n-1;i>=0;i--) {
        if(arr[i] <= least) {
            least = arr[i];
        }
        leastOnRight[i] = least;
    }

    int greatest=arr[0];
    for(int i=1;i<n-1;++i) {
        if(arr[i] >= greatest) {
            greatest = arr[i];
            if(arr[i] <= leastOnRight[i]) {
                return arr[i];
            }
        }
    }

    return -1;
}
