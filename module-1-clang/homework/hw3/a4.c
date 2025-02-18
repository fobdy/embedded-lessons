#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;
    int product = a * b * c;

    printf("%d+%d+%d=%d\n", a, b, c, sum);
    printf("%d*%d*%d=%d", a, b, c, product);

    return 0;
}
