#include <iostream>
#include <deque>
using namespace std;
enum Direction {NONE, UP, DOWN, SAME}
struct DirTally {
  DirTally() : dir(NONE), count(0) {}
  Direction dir;
  int count;
};
int main() {
  int n,k,i;
  cin >> n >> k;
  deque<DirTally> k_list;
  int prev_item = -1;
  //int chg_tally = 0;
  DirTally dt;
  Direction new_dir=NONE;
  i=0; // maintains the count
  while(n--) {
    int item;
    cin >> item;
    int chg=0;
    if(prev_item != -1) {
      new_dir=item > prev_item ? UP:(item < prev_item ? DOWN:SAME);
      if(new_dir != dt.dir) {
        k_list.push_back(dt);
        dt.count=1;
        dt.dir=new_dir;
      }
    }
    prev_item = item;
    if(i > 0 && i % k == 0) {
      cout << calc_score(k_list) << endl;
      DirTally firstEl = k_list.front();
      k_list.pop_front();
      firstEl.count--;
      if (firstEl.count > 0) {
        k_list.push_front(firstEl)
      } 
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
