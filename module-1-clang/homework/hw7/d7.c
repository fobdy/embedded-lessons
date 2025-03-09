#include <stdio.h>

void print_sequence(unsigned int value) {
    printf("%d ", value);

    if (value > 1) {
        print_sequence(value - 1);
    }
}

void main() {
    unsigned int n = 0;
    scanf("%u", &n);

    print_sequence(n);
}
