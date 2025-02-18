#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int min = a;

    min = b < min ? b : min;
    min = c < min ? c : min;
    min = d < min ? d : min;
    min = e < min ? e : min;

    printf("%d", min);

    return 0;
}
