#include <stdio.h>
int tilde(int a)
{
    return (a<0)?((-a)+1):(-((((a>=0)?a:(-a))+1)));
}
int main(int argc, const char** argv) {
    int a;
    scanf("%d",&a);
    printf("\n%d\n",a);
    // a = ~a;
    a = tilde(a);
    printf("\n%d\n",a);
    return 0;
}