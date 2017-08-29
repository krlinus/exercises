#include <iostream>
#include <deque>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  deque<int> k_list;
  enum direction {NONE, INCR, DECR, EQUAL} dir;
  int prev_item=0;
  int item_no=0,dir_start=0; 
  while(n--) {
    int item;
    cin >> item;
    direction new_dir = NONE;
    if(prev_item) {
      if(item > prev_item) new_dir = INCR;
      else if(item < prev_item) new_dir = DECR;
      else new_dir = EQUAL;
      if (dir == NONE) dir = new_dir;
    }
    if (new_dir != dir) {
      if(
    }
    item_no++;
  }
  cout <<endl;
  return 0;
}
#if 0
21 4
1 2 3 2 1 5 3 2 2 4 3 5 6 4 2 2 1 0 2 5 5
      1 -1 -1 -1 -1 -2 0 0 1 1 1 -1 -2 -2 -2 -1 1 2
#endif
