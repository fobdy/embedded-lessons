#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    char line[102] = "\0";

    if (file == NULL) {
        return 1;
    }

    size_t len = 0;

    if (fgets(line, sizeof(line), file) != NULL) {
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len -= 1;
        } else if (len > 1 && line[len - 1] == '\n' && line[len - 2] == '\r') {
            line[len - 2] = '\0';
            len -= 2;
        }
    } else {
        fclose(file);
        return 1;
    }

    fclose(file);

    FILE *output = fopen("output.txt", "w");
    if (output != NULL) {
        fprintf(output, "%s, %s, %s %lu", line, line, line, len);
        fclose(output);
    } else {
        return 1;
    }

    return 0;
}