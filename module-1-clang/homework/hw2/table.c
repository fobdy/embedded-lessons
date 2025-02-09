#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    printf("%10s%10s%13s%25s\n", "a", "b", "!a || b", "(a && b) || (!a && !b)");

    unsigned char x = 0;

    for (int i = 0; i < 4; i++)
    {
        bool b = x & 1;
        bool a = (x >> 1) & 1;
        bool impl = !a || b;
        bool equal = (a && b) || (!a && !b);

        printf("%10d%10d%13d%25d\n", a, b, impl, equal);

        x += 1;
    }

    return 0;
}
