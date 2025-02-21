#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int8_t a = 0;
    int8_t b = 0;

    scanf("%" SCNi8 " %" SCNi8, &a, &b);

    int8_t i;

    for (i = a; i < b; i++) {
        printf("%d ", i * i);
    }
    printf("%d", i * i);

    return 0;
}
