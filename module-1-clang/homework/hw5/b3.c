#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int8_t a = 0;
    int8_t b = 0;

    scanf("%" SCNi8 " %" SCNi8, &a, &b);

    int8_t i;
    int32_t sum = 0;

    for (i = a; i <= b; i++) {
        sum += i * i;
    }
    printf("%" PRId32, sum);

    return 0;
}