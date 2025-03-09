#include <stdio.h>

void dec2bin(unsigned int value) {
    if (value >= 2) {
        dec2bin(value / 2);
    }
    printf("%d", value % 2);
}

void main() {
    unsigned int n = 0;
    scanf("%u", &n);

    dec2bin(n);
}
