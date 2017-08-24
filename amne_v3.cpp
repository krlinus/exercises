#include <iostream>
#include <deque>
using namespace std;
int calc_score(const deque<int> &d) {
  int incr,decr, sum_incr, sum_decr;
  incr=decr=sum_incr = sum_decr = 0;
  cout << "calc_score: d.size = " << d.size() << endl;
  enum direction {SAME, INCR, DECR, NONE} dir;
  dir=NONE;
  for(int i=0;i<d.size()-1;++i) {
    cout << d[i] <<"," << d[i+1] << endl;
    if(d[i+1] > d[i]) {
      if(dir == INCR || dir == NONE) {
        incr++;
        if(dir==NONE) incr++;
        dir=INCR;
      } else if(dir == DECR) {
        sum_decr += (decr * (decr+1))/2 - decr;
        decr=0;
        dir = INCR;
      }
    } else if(d[i+1] < d[i]) {
      if(dir == DECR || dir == NONE) {
        decr++;
        if(dir==NONE) decr++;
        dir=INCR;
      } else if(dir == INCR || dir == NONE) {
        sum_incr += (incr * (incr+1))/2 - incr;
        incr=0;
        dir = DECR;
      }
    } else if (d[i+1] == d[i]) {
      if(incr) {
        sum_incr += (incr * (incr+1))/2 - incr;
        incr=0;
      }else if(decr) {
        sum_decr += (decr * (decr+1))/2 - decr;
        decr=0;
      }
      dir=SAME;
    }
    cout << "incr = " << incr << "; decr = "<< decr << endl;
  }
  if(incr) {
    sum_incr += (incr * (incr+1))/2 - incr;
  }
  if(decr) {
    sum_decr += (decr * (decr+1))/2 - decr;
  }
  return sum_incr - sum_decr;
}

int main() {
  int n,k;
  cin >> n >> k;
  deque<int> k_list;
  while(n--) {
    int item;
    cin >> item;
    k_list.push_back(item);
    if(k_list.size() == k) {
      cout << calc_score(k_list) << endl;
      k_list.pop_front();
    }
  }
  cout <<endl;
  return 0;
}
#if 0
21 4
1 2 3 2 1 5 3 2 2 4 3 5 6 4 2 2 1 0 2 5 5
      1 -1 -1 -1 -1 -2 0 0 1 1 1 -1 -2 -2 -2 -1 1 2
#endif
