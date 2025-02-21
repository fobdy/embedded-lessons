#include <stdio.h>

int cumsum(int value) {
    int sum = 0;
    for (int i = 1; i <= value; i++) {
        sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    int number = 0;

    scanf("%d", &number);

    printf("%d", cumsum(number));

    return 0;
}
