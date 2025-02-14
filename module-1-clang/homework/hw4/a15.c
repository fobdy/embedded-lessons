#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    float k = (y2 - y1) / (float)(x2 - x1);
    float b = y1 - k * x1;

    printf("%.2f %.2f", k, b);

    return 0;
}
