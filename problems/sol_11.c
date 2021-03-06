#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int cut(int* arr, int sz, int *min){
    int leftover=0;
    int newmin=INT_MAX;
    for(int i=0;i<sz;++i) {
        if(arr[i] > 0) {
            arr[i] -= *min;
            if(arr[i] > 0 && arr[i] < newmin)
                newmin = arr[i];
        }
        if(arr[i]>0) leftover++;
    }
    *min=newmin;
    return leftover;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int min=INT_MAX;
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
       if(arr[arr_i] < min) min = arr[arr_i];
    }
    int leftover = n;
    do {
        printf("%d\n", leftover);
    } while((leftover = cut(arr,n,&min)) > 0);
    return 0;
}


#if 0 
/* Cleaner solution - count the number of occurances of each number
then go over it from smallest to greatest order while subtracting the
# of occurances from the number of numbers
*/
int main(){
    int n; 
    int h[1000] = {0};
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
       h[arr[arr_i]]++;
    }
    
    for(int i=0;i<1000;++i) {
        if(h[i]){
            printf("%d\n",n);
            n -= h[i];
            
        }
    }
    return 0;
}
#endif
