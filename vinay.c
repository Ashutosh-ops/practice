#include <stdio.h>

int main(int argc, const char **argv)
{
    int a,i,j, flag = 0;
    scanf("%d", &a);
    for (i = 2; i < a; i++)
    {
        flag = 0;
        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        printf("%d", i);
    }
    return 0;
}