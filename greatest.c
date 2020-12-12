#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b,c,r;
    scanf("%d%d%d",&a,&b,&c);
    r=(a>b)?(a>c)?a:c:(b>c)?b:c;
    printf("\nGreatest number is: %d\n",r);
    return 0;
}
