#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, d, r;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    r = (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
    if (d >= r)
    {
        printf("\nGreatest number is: %d\n", d);
    }
    else
    {
        if (a == r)
        {
            printf("\na is Greatest number is: %d\n", a);
        }
        else if (r == b)
        {
            printf("\nb is Greatest number is: %d\n", b);
        }
        else
        {
            printf("\nc is Greatest number is: %d\n", c);
        }
    }
    return 0;
}
