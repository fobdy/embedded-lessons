#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort_array(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void main() {
    const size_t ARRAY_LEN = 5;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    sort_array(ARRAY_LEN, numbers);

    for (int i = 0; i < ARRAY_LEN; i++) {
        printf("%d ", numbers[i]);
    }
}
