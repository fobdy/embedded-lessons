#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    printf("%s", a < b && b < c ? "YES" : "NO");

    return 0;
}
