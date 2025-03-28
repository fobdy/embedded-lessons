#include <stdio.h>
#include <string.h>

int write_to_output(char *str) {
    FILE *file = fopen("output.txt", "w");
    if (file != NULL) {
        fputs(str, file);
        fclose(file);
    } else {
        return 1;
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        return 1;
    }

    unsigned int len = 0;
    char output[27] = "\0";

    if (fscanf(input_file, "%u", &len) != 1) {
        fclose(input_file);
        return 1;
    }
    fclose(input_file);

    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            output[i] = 'A' + (i / 2);
        } else {
            output[i] = '0' + (i - 1) % 8 + 2;
        }
    }

    output[len] = '\0';

    write_to_output(output);

    return 0;
}