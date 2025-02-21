#include <stdio.h>

int f(int x) {
    if (x >= -2 && x < 2) {
        return x * x;
    } else if (x >= 2) {
        return x * x + 4 * x + 5;
    } else {
        return 4;
    }
}

int main() {
    int max = 0;
    int x = 0;
    int sign = 1;
    unsigned char c;

    while (1) {
        c = getchar();

        if (c >= '0' && c <= '9') {
            x = x * 10 + c - '0';
        } else if (c == '-') {
            sign = -1;
        } else if (c == ' ') {
            x = f(sign * x);
            max = x > max ? x : max;
            x = 0;
            sign = 1;
        } else if (c == '\n') {
            break;
        }
    }

    printf("%d", max);

    return 0;
}
