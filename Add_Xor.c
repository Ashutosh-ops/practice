#include<stdio.h>
 
int main()
{
    int a=0, b=0, c=0;
    printf("\nEnter two numbers: ");
    scanf("%d%d", &a, &b);
    while (b != 0)
    {
        c = a & b;
        a = a ^ b; 
        b = c << 1;
    }
    printf("\nSum is %d\n", a);
    return 0;
}