#include <stdio.h>

int power(int base, unsigned int exponent) {
    int result = 1;
    unsigned int i = 0;

    for (i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    int base = 0;
    int exponent = 0;

    scanf("%d %d", &base, &exponent);

    printf("%d", power(base, exponent));

    return 0;
}
