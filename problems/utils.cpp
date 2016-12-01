#include <vector>
#include <iostream>

/* fills positive numbers in passed vector.
 * Returns number of elements added
 */
int get_int_vect(std::vector<int> &arr) {
  int i = 0;
  int n = 0;
  while(true) {
    std::cin >> i;
    if (i < 0) {
      break;
    }
    n++;
    arr.push_back(i);
  }
  return n;
}

int dump_vect(const std::vector<int> &v) {
  const int sz = v.size();
  for(int i=0;i < sz;++i) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  return sz;
}
