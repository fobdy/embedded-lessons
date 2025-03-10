#include <assert.h>
#include <stdio.h>

size_t min_index(int numbers[], size_t len) {
    assert(len > 0 && "Array should contain at least one element");

    int min = numbers[0];
    size_t index = 0;

    for (int i = 1; i < len; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            index = i;
        }
    }

    return index;
}

size_t max_index(int numbers[], size_t len) {
    assert(len > 0 && "Array should contain at least one element");

    int max = numbers[0];
    size_t index = 0;

    for (int i = 1; i < len; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            index = i;
        }
    }

    return index;
}

void main() {
    const size_t ARRAY_LEN = 10;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    size_t i_max = max_index(numbers, ARRAY_LEN);
    size_t i_min = min_index(numbers, ARRAY_LEN);

    printf("%ld %d %ld %d", i_max + 1, numbers[i_max], i_min + 1, numbers[i_min]);
}
