#include <vector>
#include <iostream>
using namespace std;

void iterate_using_const_iterator(const vector<int>& vect) {
  // iterate using iterator
  for(vector<int>::const_iterator i = vect.begin(); // needs const_iterator because the var is const
      i != vect.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;
}
void iterate_using_iterator(vector<int>& vect) {
  // iterate using iterator
  for(vector<int>::iterator i = vect.begin();
      i != vect.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vect;

  // Insert at end: constant time
  vect.push_back(42);

  // Insert one more
  vect.push_back(22);

  // Insert at start
  vect.insert(vect.begin(), 142);

  iterate_using_iterator(vect); //  142 42 22


  // insert in the middle
  vect.insert(vect.begin() + 1, 242);

  iterate_using_iterator(vect); // 142 242 42 22

  // using at()
  try {
    cout << vect.at(10); // should throw, because currently it has 5 elements
  } catch (const out_of_range & oor) {
    cout << oor.what();
    // it says: vector::_M_range_check: __n (which is 10) >= this->size() (which is 4)
  }
  vect.pop_back();
  cout << "popping back ..." << endl;

  iterate_using_iterator(vect); //  142 242 42 

}
