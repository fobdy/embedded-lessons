#include <stdio.h>

int main(int argc, char const *argv[]) {
    int inp = 0;

    scanf("%d", &inp);

    int a = inp % 10;
    int b = inp % 100 / 10;
    int c = inp / 100;

    int max = a;

    max = b > max ? b : max;
    max = c > max ? c : max;

    printf("%d", max);

    return 0;
}
