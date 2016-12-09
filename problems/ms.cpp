#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;


void merges(vector<int> &arr, int start, int end) {
  int mid=(start+end)/2;
  if(mid - start > 1) merges(arr,start,mid);
  if(end - mid > 1) merges(arr,mid,end);
  cout << "------------------" << endl;
  dump_vect(arr);
  cout << "------------------" << endl;
  vector<int> tmp;
  for(int i=start, j=mid;i<mid || j < end;) {
    if(j >= end || (i < mid && arr[i] < arr[j])) {
      tmp.push_back(arr[i]);
      i++;
    } else {
      tmp.push_back(arr[j]);
      j++;
    }
  }
  for(int i=0;i<tmp.size();++i) {
    arr[i+start] = tmp[i];
  }

}

int main() {
  vector<int> arr;
  cout << "start: " << endl;
  const int alen = get_int_vect(arr);
  dump_vect(arr);
  merges(arr, 0, alen);
  dump_vect(arr);

  return 0;
}

