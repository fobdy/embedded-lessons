#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);

    if (a < b) {
        printf("%d %d", a, b);
    } else {
        printf("%d %d", b, a);
    }

    return 0;
}
