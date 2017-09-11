#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

bool sort_func(const pair<long,long> &p1,
               const pair<long,long> &p2) {
    if(p1.first < p2.first) return true;
    if(p1.first == p2.first && p1.second < p2.second) return true;
    return false;
}
#if 0
In file included from /usr/include/c++/4.8/algorithm:62:0,
                 from q_attack.cpp:21:
/usr/include/c++/4.8/bits/stl_algo.h: In instantiation of ‘bool std::binary_search(_FIter, _FIter, const _Tp&) [with _FIter = __gnu_cxx::__normal_iterator<std::pair<long int, long int>*, std::vector<std::pair<long int, long int> > >; _Tp = long int]’:
q_attack.cpp:61:52:   required from here
/usr/include/c++/4.8/bits/stl_algo.h:2710:39: error: no match for ‘operator<’ (operand types are ‘const long int’ and ‘std::pair<long int, long int>’)
       return __i != __last && !(__val < *__i);
                                       ^

#endif
int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    vector<pair<long,long>> obs;
    cin >> rQueen >> cQueen;
    rQueen--;
    cQueen--;
    for(int a0 = 0; a0 < k; a0++){
        long rObstacle;
        long cObstacle;
        cin >> rObstacle >> cObstacle;
        rObstacle--;
        cObstacle--; // make 0-based index
        obs.push_back(make_pair(rObstacle,cObstacle));
        // your code goes here
    }
    sort(obs.begin(),obs.end(),sort_func);
    // trace Q's attacks on all 8 directions
    int atk_pos=0;
    for(long r=rQueen, c=cQueen;r < n-1 && c < n-1;){
        r++;
        c++;
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),make_pair(r,c)))
            atk_pos++;
        else
            break;
    }
    cerr << "1." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;r > 0 && c > 0;){
        r--;
        c--;
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq))
            atk_pos++;
        else
            break;
    }
    cerr << "2." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;r > 0 && c < n-1;){
        r--;
        c++;
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq))
            atk_pos++;
        else
            break;
    }
    cerr << "3." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;r < n-1 && c > 0;){
        r++;
        c--;
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq))
            atk_pos++;
        else
            break;
    }
    cerr << "4." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;r < n-1;){
        r++;
        
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq))
            atk_pos++;
        else
            break;
    }
        cerr << "5." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;r > 0;){
        r--;
        
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq))
            atk_pos++;
        else
            break;
    }
        cerr << "6." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;c < n-1;){
        c++;
        
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq) )
            atk_pos++;
        else
            break;
    }
        cerr << "7." << atk_pos << endl;
    for(long r=rQueen, c=cQueen;c > 0;){
        c--;
        
        pair<long,long> sq = make_pair(r,c);
        if(!binary_search(obs.begin(), obs.end(),sq))
            atk_pos++;
        else
            break;
    }
        cerr << "8." << atk_pos << endl;
    cout << atk_pos;
    return 0;
}

