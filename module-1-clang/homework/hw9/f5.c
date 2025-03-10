#include <stdio.h>

int find_max_array(int size, int a[]) {
    int max = a[0];

    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

void main() {
    const size_t ARRAY_LEN = 10;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    float max = find_max_array(ARRAY_LEN, numbers);

    printf("%d", max);
}
