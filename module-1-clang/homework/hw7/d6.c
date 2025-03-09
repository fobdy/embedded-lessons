#include <stdio.h>

void main() {
    char one_char;
    scanf("%c", &one_char);

    if (one_char != '.') {
        main();
        printf("%c", one_char);
    }
}
