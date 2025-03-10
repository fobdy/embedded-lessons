#include <stdio.h>

void print_digit(char s[]) {
    int counter[10] = {0};
    unsigned int i = 0;

    while (s[i] != 0) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            c = c - '0';
            counter[c] += 1;
        }

        i++;
    }

    for (int i = 0; i < 10; i++) {
        if (counter[i] != 0) {
            printf("%d %d\n", i, counter[i]);
        }
    }
}

void main() { print_digit("Hello123 world77."); }
