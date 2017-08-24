#include <iostream>
#include <deque>
using namespace std;
int calc_score(const deque<int> &d) {
  int t_chg, sum_incr, sum_decr;
  sum_incr = sum_decr = 0;
  t_chg = d[0];
  cout << "calc_score: d.size = " << d.size() << endl;
  cout << "t_chg = " << t_chg << endl;
  for(int i=1;i<d.size();++i) {
    if(d[i] == d[i-1]) {
      t_chg += d[i];
      if(d[i] > 0) {
        sum_incr = (t_chg * (t_chg+1))/2 - t_chg;
      } else if (d[i] < 0) {
        sum_decr = (t_chg * (t_chg+1))/2 - t_chg;
      }
    } else {
      if (t_chg < 0) t_chg = -t_chg;
      if(d[i] < d[i-1]) {
        sum_incr += (t_chg * (t_chg+1))/2 - t_chg;
      } else {
        sum_decr += (t_chg * (t_chg+1))/2 - t_chg;
      }
      t_chg=d[i];
    }
    cout << "t_chg = " << t_chg << endl;
  }
  return sum_incr - sum_decr;
}

int main() {
  int n,k;
  cin >> n >> k;
  deque<int> k_list;
  int prev_item = -1;
  int chg=0;
  //k_list.push_back(chg);
  while(n--) {
    int item;
    cin >> item;
    cout << "prev_item="<<prev_item<<"; item="<<item<<endl;
    if(prev_item != -1) {
      chg=item > prev_item ? 1:(item < prev_item ? -1:0);
      cout<<"chg = "<<chg<<endl;
      k_list.push_back(chg);
    }
    prev_item = item;
    if(k_list.size() >= k) {
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
