#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;

int heap_insert(vector<int> &heap, int new_el) {
  heap.push_back(new_el);
  int nswaps = 0;
  int hlen = heap.size();
  int el_pos = hlen - 1;
  int i = el_pos / 2;
  while(heap[el_pos] > heap[i]) {
    int t = heap[i];
    heap[i] = heap[el_pos];
    heap[el_pos] = t;
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

