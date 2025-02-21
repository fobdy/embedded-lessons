#include <stdio.h>

int main(int argc, char const *argv[]) {
    int len = 0;

    scanf("%d", &len);

    for (int i = 1; i <= len; i++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
    }

    return 0;
}
