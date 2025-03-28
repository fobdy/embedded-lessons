#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int readline(char *filename, char *buf, size_t bufsize, size_t *length) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return 1;
    }

    size_t len = 0;

    if (fgets(buf, bufsize, file) != NULL) {
        len = strlen(buf);

        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
            len -= 1;
        } else if (len > 1 && buf[len - 1] == '\n' && buf[len - 2] == '\r') {
            buf[len - 2] = '\0';
            len -= 2;
        }
    } else {
        fclose(file);
        return 1;
    }
    fclose(file);

    *length = len;

    return 0;
}

int main() {
    char buf[1002] = "\0";
    size_t len = 0;

    if (readline("input.txt", buf, sizeof(buf), &len) == 0) {
        char lastchar = buf[len - 1];
        FILE *f = fopen("output.txt", "w");
        bool at_least_one_found = false;

        for (int i = 0; i < len - 1; i++) {
            if (buf[i] == lastchar) {
                if (at_least_one_found) {
                    fprintf(f, " %d", i);
                } else {
                    at_least_one_found = true;
                    fprintf(f, "%d", i);
                }
            }
        }
        fclose(f);
    } else {
        return 1;
    }
}