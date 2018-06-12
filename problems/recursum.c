/*
Given an array, arr, of integers, write a recursive function that add sum of all the previous numbers to each index of the array. For example, if input array is

[1, 2, 3, 4, 5, 6]

the function should update the array to
[1, 3, 6, 10, 15, 21]

Meenakshi. Dynamic Programming for Coding Interviews: A Bottom-Up approach to problem solving (p. 5). Notion Press. Kindle Edition. 
*/

int accu(int *arr, int sz) {
    if(sz <= 0) return 0;

    arr[sz-1] += accu(arr,sz - 1);
    return arr[sz-1];
}

int main() {
    int arr[] = { 1,2,3,4,5,6};
    accu(arr, sizeof(arr)/sizeof(int));
    for(int i=0;i<sizeof(arr)/sizeof(int);++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

