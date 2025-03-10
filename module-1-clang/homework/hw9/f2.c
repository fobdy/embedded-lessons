#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort_even_odd(int n, int a[]) {
    for (int j = 1; j < n; j++) {
        bool is_sorted = true;
        for (int i = 0; i < n - j; i++) {
            if (a[i] % 2 != 0 && a[i + 1] % 2 == 0) {
                swap(&a[i], &a[i + 1]);
                is_sorted = false;
            }
        }
        if (is_sorted) {
            break;
        }
    }
}

void main() {
    const size_t ARRAY_LEN = 5;

    int numbers[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &numbers[i]);
    }

    sort_even_odd(ARRAY_LEN, numbers);

    for (int i = 0; i < ARRAY_LEN; i++) {
        printf("%d ", numbers[i]);
    }
}
