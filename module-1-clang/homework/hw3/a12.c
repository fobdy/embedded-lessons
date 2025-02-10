#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;

    scanf("%d", &a);

    int first = a % 10;
    int second = a % 100 / 10;
    int third = a / 100;

    printf("%d", first + second + third);

    return 0;
}
