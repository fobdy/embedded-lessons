#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPH_SIZE 26
#define WORD_BUF_LEN 101

int panic(const char *error_msg) {
    fprintf(stderr, "Fatal error: %s.\n", error_msg);
    exit(1);
}

void count_chars(char *str, unsigned int *counter) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            counter[c - 'a'] += 1;
        }
    }
}

int main() {
    ALPH_SIZE == ('z' - 'a' + 1) || panic("Invalid size of english alphabet is defined");

    char word1[WORD_BUF_LEN] = "\0";
    char word2[WORD_BUF_LEN] = "\0";

    unsigned int counter1[ALPH_SIZE] = {0};
    unsigned int counter2[ALPH_SIZE] = {0};

    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%s", word1) == 1 || panic("Could not read first word from input file");
    fscanf(file, "%s", word2) == 1 || panic("Could not read second word from input file");
    fclose(file);

    count_chars(word1, counter1);
    count_chars(word2, counter2);

    FILE *f = fopen("output.txt", "w");
    bool at_least_one_found = false;

    for (int i = 0; i < ALPH_SIZE; i++) {
        if (counter1[i] == 1 && counter2[i] == 1) {
            if (at_least_one_found) {
                fprintf(f, " %c", 'a' + i);
            } else {
                at_least_one_found = true;
                fprintf(f, "%c", 'a' + i);
            }
        }
    }
    fclose(f);
}