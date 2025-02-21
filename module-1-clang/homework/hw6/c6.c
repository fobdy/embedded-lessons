#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint64_t power(int base, unsigned int exponent) {
    uint64_t result = 1;
    unsigned int i;

    for (i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

uint64_t geom_prog(unsigned int index) {
    const int b1 = 1;
    const int q = 2;

    return b1 * power(q, index - 1);
}

int main() {
    int index = 0;

    scanf("%d", &index);

    printf("%" PRIu64, geom_prog(index));

    return 0;
}
