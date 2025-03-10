#include <stdio.h>

float avg(int numbers[], size_t len) {
    unsigned int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += numbers[i];
    }

    return (float)sum / len;
}

void main() {
    const size_t ARRAY_LEN = 5;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    float average = avg(numbers, ARRAY_LEN);

    printf("%.3f", average);
}
