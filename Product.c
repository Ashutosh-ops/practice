#include <stdio.h>

void fun(int x, int y)
{
    printf("%d %d\n",x++,y--);
}

int main(int argc, char const *argv[])
{
    int i=5;
    fun(--i,i++);
    fun(++i,i--);
    printf("%d\n",i++);
    return 0;
}
