#include <stdio.h>

void main() {
    int counter[10] = {0};
    unsigned char c;

    while (1) {
        c = getchar();
        if (c >= '0' && c <= '9') {
            c = c - '0';
            counter[c] += 1;
        } else if (c == '\n' || c == ' ') {
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (counter[i] != 0) {
            printf("%d %d\n", i, counter[i]);
        }
    }
}
