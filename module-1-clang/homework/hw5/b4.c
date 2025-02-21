#include <stdio.h>

int main(int argc, char const *argv[]) {
    int number = 0;

    scanf("%d", &number);

    int len = 0;

    while (number > 0) {
        len += 1;
        number /= 10;
    }

    if (len == 3) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
