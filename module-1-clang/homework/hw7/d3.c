#include <stdio.h>

void print_digits(unsigned int value) {
    printf("%d ", value % 10);
    value = value / 10;
    if (value == 0) {
        return;
    }
    print_digits(value);
}

void main() {
    unsigned int n = 0;
    scanf("%u", &n);

    print_digits(n);
}
