#include <stdio.h>
#include <stdlib.h>

int panic(const char *error_msg) {
    fprintf(stderr, "Fatal error: %s.\n", error_msg);
    exit(1);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    (input != NULL && output != NULL) || panic("could not open files");

    int c;

    while ((c = fgetc(input)) != EOF) {
        if (c == 'a' || c == 'A') {
            c += 1;
        } else if (c == 'b' || c == 'B') {
            c -= 1;
        }
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
}