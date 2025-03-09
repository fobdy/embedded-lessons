#include <stdio.h>

unsigned int calc_sum(unsigned int value) {
    if (value <= 1) {
        return value;
    }
    return value + calc_sum(value - 1);
}

void main() {
    unsigned int n = 0;
    scanf("%u", &n);

    unsigned int sum = calc_sum(n);
    printf("%u", sum);
}
