#include <assert.h>
#include <stdio.h>

long int sum_of_positives(int numbers[], size_t len) {
    long int sum = 0;

    for (int i = 0; i < len; i++) {
        if (numbers[i] > 0) {
            sum += numbers[i];
        }
    }

    return sum;
}

void main() {
    const size_t ARRAY_LEN = 10;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    long int sum = sum_of_positives(numbers, ARRAY_LEN);

    printf("%ld", sum);
}
