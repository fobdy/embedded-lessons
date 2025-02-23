#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint64_t fact(unsigned int n) {
    uint64_t f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    unsigned int n = 0;

    scanf("%u", &n);

    printf("%" PRIu64, fact(n));

    return 0;
}
