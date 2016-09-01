#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
    
int main(int argc, char* argv[]) {
    uint32_t start = 0x5a7de2;
    uint32_t a = start;
    int i;    
    for(i = 1;; i++) {
        int newbit = (((a >> 22) ^ (a >> 17)) & 1);
        a = ((a << 1) | newbit) & 0x7fffff;
        printf("%x\n", a);
        if (a == start) {
            printf("repetition period is %x\n", i);
            break;
        }
    }
}
