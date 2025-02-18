#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    int result = a + b + c;

    printf("%d+%d+%d=%d", a, b, c, result);

    return 0;
}
