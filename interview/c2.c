#include <stdio.h>

int square(volatile int *ptr)
{

return *ptr * *ptr;

}

int main() {
    volatile int p = 2;
    printf("%d\n", square(&p));
    return 0;
}
