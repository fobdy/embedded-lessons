#include <assert.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

long int sum_of_two_max(int numbers[], size_t len) {
    assert(len > 1 && "Array should contain at least two elements");

    int max_one = numbers[0];
    int max_two = numbers[1];

    if (max_one < max_two) {
        swap(&max_one, &max_two);
    }

    for (int i = 2; i < len; i++) {
        if (numbers[i] > max_one) {
            max_two = max_one;
            max_one = numbers[i];
        } else if (numbers[i] > max_two) {
            max_two = numbers[i];
        }
    }

    return (long int)max_one + max_two;
}

void main() {
    const size_t ARRAY_LEN = 10;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    long int sum = sum_of_two_max(numbers, ARRAY_LEN);

    printf("%ld", sum);
}
