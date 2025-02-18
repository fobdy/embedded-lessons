#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    uint8_t month = 0;

    scanf("%" SCNu8, &month);

    if (month >= 3 && month <= 5) {
        printf("spring"); // 3, 4, 5
    } else if (month >= 6 && month <= 8) {
        printf("summer"); // 6, 7, 8
    } else if (month >= 9 && month <= 11) {
        printf("autumn"); // 9, 10, 11
    } else {
        printf("winter"); // 12, 1, 2
    }

    return 0;
}
