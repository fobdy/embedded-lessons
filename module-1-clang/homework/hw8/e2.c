#include <assert.h>
#include <stdio.h>

int min(int numbers[], size_t len) {
    assert(len > 0 && "Array should contain at least one element");

    int min = numbers[0];

    for (int i = 1; i < len; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    return min;
}

void main() {
    const size_t ARRAY_LEN = 5;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    int minimum = min(numbers, ARRAY_LEN);

    printf("%d", minimum);
}
