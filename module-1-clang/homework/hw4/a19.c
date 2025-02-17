#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    bool aboveZero = a > 0 && b > 0 && c > 0;
    bool twoSidesGreaterThanThirdOne = (a + b) > c && (b + c) > a && (a + c) > b;

    if (aboveZero && twoSidesGreaterThanThirdOne)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
