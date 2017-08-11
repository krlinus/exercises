#include <iostream>
#include <deque>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  deque<int> k_list;
  int prev_item = -1;
  int chg_tally = 0;
  while(n--) {
    int item;
    cin >> item;
    int chg=0;
    if(prev_item != -1) {
      chg=item > prev_item ? 1:(item < prev_item ? -1:0);
      k_list.push_back(chg);
      chg_tally += chg;
    }
    prev_item = item;
    if(k_list.size() >= k-1) {
      cout << chg_tally << endl;
      chg_tally -= k_list.front();
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
