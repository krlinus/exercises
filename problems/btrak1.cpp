#include <iostream>

int maxset(int *in, int *res, const int in_sz, int max_res_sz, int in_idx, int res_idx) {
	/*
int *in, // full input array
int *res,//result array
const int in_sz, // size of the input array
int max_res_sz, // max size of legitimate results so far
int in_idx, // current input element's index under consideration
int res_idx // current point of appending to result set
) {
	*/
	// half ass backtrack. to be completed.
	int i;
	for(i=0;i<res_idx;++i) {
		if((res[i] + in[in_idx]) % k == 0) break;
	}
	if(i == res_idx) {
		res[res_idx++] = in[in_idx++];
	} else {
		in_idx++;
	}
	if(in_idx < in_sz - 1) {
		if(res_idx > max_res_sz) max_res_sz = res_idx;
		max_res_sz = maxset(in,res,in_sz,max_res_sz,in_idx,res_idx);
	} else {

	}


	return max_res_sz;
}

int main() {
	int n,k;
	int *in_arr, *res_arr;
	std::cin >> n >> k;
	int i=n;
	in_arr=new int[n];
	out_arr=new int[n];
	do {
		i--;
		std::cin >> in_arr[i];
		res_arr[i]=-1;
	} while(i>0);
	std::cout << maxset(in_arr,res_arr,n,1,1,1);
