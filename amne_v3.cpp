#include <iostream>
#include <deque>
using namespace std;
int calc_score(const deque<int> &d) {
  int t_chg, sum_incr, sum_decr;
  t_chg = sum_incr = sum_decr = 0;
  int prev_chg=0;
  for(int i=1;i<d.size();++i) {
    if(d[i] == d[i-1]) {
      t_chg += d[i];
    } else if(d[i] < d[i-1]) {
      sum_incr += (t_chg * (t_chg+1))/2;
      t_chg=d[i];
    } else if(d[i] > d[i-1]) {
      sum_decr += (t_chg * (t_chg+1))/2;
      t_chg=d[i];
    }
  }
  return sum_incr + sum_decr;
}

int main() {
  int n,k;
  cin >> n >> k;
  deque<int> k_list;
  int prev_item = -1;
  //int chg_tally = 0;
  while(n--) {
    int item;
    cin >> item;
    int chg=0;
    if(prev_item != -1) {
      chg=item > prev_item ? 1:(item < prev_item ? -1:0);
      k_list.push_back(chg);
      //chg_tally += chg;
    }
    prev_item = item;
    if(k_list.size() >= k-1) {
      cout << calc_score(k_list) << endl;
      //chg_tally -= k_list.front();
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
