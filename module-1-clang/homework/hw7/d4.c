#include <stdio.h>

void print_digits(unsigned int value) {
    if (value >= 10) {
        print_digits(value / 10);
    }
    printf("%d ", value % 10);
}

void main() {
    unsigned int n = 0;
    scanf("%u", &n);

    print_digits(n);
}
