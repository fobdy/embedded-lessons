#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    int max = a;

    max = b > max ? b : max;
    max = c > max ? c : max;

    printf("%d", max);

    return 0;
}
