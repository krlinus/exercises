#include <stdio.h>

void printb(int n) {
    const static char cmap[][5] = {"0000", "0001", "0010", "0011", "0100", "0101",
        "0110", "0111", "1000", "1001", "1010",
        "1011", "1100", "1101", "1110", "1111"};
    int nplaces = ((sizeof(int)*8) - 4);
    unsigned int mask = 0xF << nplaces;
    while(mask) {
        printf("%s", cmap[(n & mask) >> nplaces]);
        nplaces -= 4;
        mask >>= 4;
    }
    printf("\n");
}


int main() {
    // Set the rightmost unset bit
    int n;
    scanf("%d", &n);
    printb(n);
    n = n |  (n+1);
    printb(n);
    printf("%d\n", n);
    return 0;
}


