#include <deque>
#include <iostream>
using namespace std;

void iterate_using_const_iterator(const deque<int>& deq) {
  // iterate using iterator
  for(deque<int>::const_iterator i = deq.begin(); // needs const_iterator because the var is const
      i != deq.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;
}
void iterate_using_iterator(deque<int>& deq) {
  // iterate using iterator
  for(deque<int>::iterator i = deq.begin();
      i != deq.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;
}

int main() {
  deque<int> deq;

  // Insert at end: constant time
  deq.push_back(42);

  // Insert one more
  deq.push_back(22);

  // Insert at start: constant time
  deq.push_front(142);

  iterate_using_iterator(deq); //  142 42 22


  // insert in the middle
  deq.insert(deq.begin() + 1, 242);

  iterate_using_iterator(deq); // 142 242 42 22

  // using at()
  try {
    cout << deq.at(10); // should throw, because currently it has 5 elements
  } catch (const out_of_range & oor) {
    cout << oor.what();
    // it says: deque::_M_range_check: __n (which is 10) >= this->size() (which is 4)
  }
  deq.pop_front();
  cout << "popping front ..." << endl;

  iterate_using_iterator(deq); //  242 42 22

}
