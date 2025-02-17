#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);

    if (a > b)
    {
        printf("Above");
    }
    else if (a < b)
    {
        printf("Less");
    }
    else
    {
        printf("Equal");
    }

    return 0;
}
