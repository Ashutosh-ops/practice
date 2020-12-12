#include<stdio.h>
 
int main()
{
    int a, b;
    printf("\n/****Swapping in one line without using bitwise operator ****/\n");
    printf("\nEnter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("\nbefore swapping: i=%d k=%d.\n", a, b);
    // a+=b - (b = a);// --> Zoran Davidovi
    // b = (a + b)-(a = b);// --> Rajat Mishra
    // a = a * b / (b = a);// -->  kongasricharan 
    a-=(b=(a+=b)-b);// --> Ashutosh Gupta
    printf("\nafter swapping: i=%d k=%d.\n", a, b);
    return 0;
}