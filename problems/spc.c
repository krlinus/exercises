#include <stdio.h>
#include <stdlib.h>
void print_surp_count(int *inp, int sz) {
    int *dp = (int*)calloc(sizeof(int), sz);
    for(int i=sz-2;i>=0;i--) {
        for(int j=i; j < sz;++j) {
            if(inp[j] > inp[i]) {
                dp[i] = dp[j]+1;
                break;
            }
        }
    }
    for(int i=0;i < sz;++i) {
        printf("%d ", dp[i]);
    }
    printf("\n");
    free(dp);
}

int main() {
    int N=0, n=0;
    fflush(stdin);
    scanf("%d",&N);
    while(N--) {
        printf("N=%d\n", N);
        scanf("%d",&n);
        printf("n=%d\n", n);
        int *arr = (int*)calloc(sizeof(int), n);
        for(int i = 0; i < n; i++) {
        printf("i=%d\n", i);
            scanf("%d", arr+i);
        }
        print_surp_count(arr, n);
        free(arr);
    }
    return 0;
}

