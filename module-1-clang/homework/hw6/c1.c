#include <stdio.h>

int abs(int value) { return value < 0 ? -value : value; }

int main(int argc, char const *argv[]) {
    int number = 0;

    scanf("%d", &number);

    printf("%d", abs(number));

    return 0;
}
