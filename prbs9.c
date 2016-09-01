#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
    
int main(int argc, char* argv[]) {
    uint32_t start = 0x4a7;
    uint32_t a = start;
    int i;    
    for(i = 1;i<512; i++) {
        int newbit = (((a >> 8) ^ (a >> 4)) & 1);
        a = ((a << 1) | newbit) & 0xfff;
        printf("%x\n", a);
        if (a&0x1ff == start) {
            printf("repetition period is %x\n", i);
            break;
        }
    }
}
