#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    float avg = (a + b + c) / 3.0;

    printf("%.2f", avg);

    return 0;
}
