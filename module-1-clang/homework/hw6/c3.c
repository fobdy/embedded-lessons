#include <stdio.h>

int average(int a, int b) {
    int result = 1;
    unsigned int i = 0;

    return (a + b) / 2;
}

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);

    printf("%d", average(a, b));

    return 0;
}
