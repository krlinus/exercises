#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;

int heap_insert(vector<int> &heap, int new_el) {
  heap.push_back(new_el);
  int nswaps = 0;
  int hlen = heap.size();
  int el_pos = hlen;
  int i = el_pos / 2;
  if (i <= 0) {
    return 0; // nothing to be done, as this is the first element
  }
  while(heap[el_pos-1] > heap[i-1]) {
    cout << "swapping " << i << " and " << el_pos << endl;
    int t = heap[i-1];
    heap[i-1] = heap[el_pos-1];
    heap[el_pos-1] = t;
    el_pos = i;
    nswaps++;
    i /= 2;
  }
  return nswaps;
}

int main() {
  vector<int> arr;
  const int alen = get_int_vect(arr);
  dump_vect(arr);
  vector<int> heap;

  for(int i=0;i<alen;++i) {
    heap_insert(heap, arr[i]);
    dump_vect(heap);
  }
  return 0;
}

