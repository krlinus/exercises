#include <stdio.h>
int add(int op1, int op2) { // 01 11
    int r1 = op1 ^ op2; // 10
    unsigned int r2 = op1 & op2; 01
    r2 <<= 1; // 10

    while(r2) { // 10
        r1 &= r2; // 
        r1 <<= 1;
        r2 ^= r1;
    }
    return r1;
}


int main() {
    for(int i=1;i<10;++i) {
        for(int j=0;j<10;++j) {
            printf("%d + %d = %d\n", i, j, add(i,j));
        }
    }
    return 0;
}
