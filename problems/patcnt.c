/*
 * 1[0]1 Pattern Count
 */
#include <assert.h>
#include <stdio.h>

int patcount(const char *arr, int sz) {
    enum State {
        OUT = 0,
        IN_1 = 1,
        IN_0 = 2
        //LAST_1 = 3
    };
    State s = OUT;
    int pc = 0;
    for(int i=0;i<sz;++i) {
        printf("s = %u, arr[i] = %c\n", s, arr[i]);
        switch (s) {
            case OUT:
                if(arr[i] == '1')
                    s = IN_1;
                break;
            case IN_1:
                if(arr[i] == '0')
                    s = IN_0;
                else if (arr[i] != '1')
                    s = OUT;
                break;
            case IN_0:
                if(arr[i] != '0') {
                    if(arr[i] == '1') {
                        pc++;
                        s = IN_1;
                    } else {
                        s = OUT;
                    }
                }
                break;
        }
    }
    printf("returning %d\n", pc);
    return pc;
}

int main() {
    assert(patcount("101", 3) == 1);
    assert(patcount("10101", 5) == 2);
    assert(patcount("100001abc101", 12) == 2);
    assert(patcount("1001ab010abc01001", 17) == 2);
    assert(patcount("0101", 4) == 1);
    assert(patcount("1n01", 4) == 0);
    assert(patcount("101n", 4) == 1);
    return 0;
}
