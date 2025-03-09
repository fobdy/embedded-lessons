#include <stdio.h>

void print(unsigned int value) {
    if (value == 0) {
        return;
    }
    print(value - 1);
    if (value == 1) {
        printf("%u", value);
    } else {
        printf(" %u", value);
    }
}

void main() {
    unsigned int n = 0;

    scanf("%u", &n);

    print(n);
}
