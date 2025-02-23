#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint64_t dec2nth(unsigned int num, unsigned int base) {
    uint64_t result = 0;
    unsigned int value = num;

    unsigned int power_val = 1;

    while (value >= base) {
        value /= base;
        power_val *= base;
    }

    value = num;
    while (power_val > 0) {
        result = result * 10 + (value / power_val);
        value = value % power_val;
        power_val /= base;
    }

    return result;
}

int main() {
    unsigned int n = 0;
    unsigned p = 0;

    scanf("%u %u", &n, &p);

    printf("%" PRIu64, dec2nth(n, p));

    return 0;
}
