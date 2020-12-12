#include<stdio.h>

int fun(int a)
{
    int c =2;
    while(a)
    {
        a = a>>=2;
        c++;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    
    printf("\n%d\n",fun(435));
    return 0;
}
