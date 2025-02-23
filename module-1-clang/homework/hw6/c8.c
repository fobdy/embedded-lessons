#include <stdio.h>

int main() {
    unsigned char c;

    while (1) {
        c = getchar();

        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        } else if (c == '.') {
            break;
        }
        printf("%c", c);
    }

    return 0;
}
