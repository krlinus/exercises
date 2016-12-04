#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;

inline void swap(vector<int> & arr, int a, int b) {
  int t = arr[a]; arr[a] = arr[b]; arr[b] = t;
}

int part(vector<int> &arr, int start, int end) {
  if(start >= end - 1) return -1;
  int mid = (start + end) / 2;
  int pivot = arr[mid];
  cout << "mid = " << mid << "; pivot= " << pivot << endl;
  swap(arr, start, mid);
  int p_ind = start + 1;
  for(int i = start + 1;i < end;++i) {
    if(arr[i] < pivot){
      swap(arr, i, p_ind);
      p_ind++;
    } 
  }
  swap(arr, start, p_ind - 1);
  dump_vect(arr);
  return p_ind;
}

int quicks(vector<int> &arr, int start, int end) {
  if (start >= end-1) {
    return 0;
  }
  int p_ind=part(arr,start,end);
  if (p_ind < 0 || end - start < 3) return 0;
  cout << "q("<<start<<","<<p_ind<<")"<<endl;
  quicks(arr,start,p_ind);
  cout << "q("<<p_ind<<","<<end<<")"<<endl;
  quicks(arr,p_ind,end);
  return 0;
}

int main() {
  vector<int> arr;
  cout << "start: " << endl;
  const int alen = get_int_vect(arr);
  dump_vect(arr);
  vector<int> heap;
  quicks(arr, 0, alen);
  dump_vect(arr);

  return 0;
}

