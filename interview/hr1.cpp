#include <cmath>
#include <limits>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, ans=numeric_limits<ll>::max();
    cin>>n;
    multiset<ll> mySet;
    for(auto i=0; i<n;++i)
    {
       ll temp=0;
       cin>>temp;
       mySet.insert(temp);
    }

    for(auto itr=mySet.begin(); itr!=mySet.end(); ++itr)
       if(itr!=mySet.begin())
       {
          ll a=*(itr--);
          ll b=*(itr++);
          ans=min(ans, abs(a-b));
       }

    cout<<ans<<endl;
    return 0;
}
