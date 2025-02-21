#include <stdio.h>

int main(int argc, char const *argv[]) {
    unsigned int number = 0;

    scanf("%d", &number);

    unsigned int sum = 0;
    unsigned char digit = 0;

    while (number > 0) {
        digit = number % 10;
        sum += digit;
        number /= 10;
    }

    printf("%d", sum);

    return 0;
}
