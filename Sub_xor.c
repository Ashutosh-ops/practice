#include <stdio.h>

int main()
{
    int a, b, c;
    printf("\nEnter two numbers: ");
    scanf("%d%d", &a, &b);
    while (b != 0)
    {
        c = (~a) & b;
        a = a ^ b;
        b = c << 1;
    }
    printf("\nSubtraction is %d\n", a);
    return 0;
}