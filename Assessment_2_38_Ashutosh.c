#include <stdio.h>
#define MAX 10
static int top = -1;
int stack[MAX];
void push(int e)
{
    if (top + 1 == MAX)
    {
        printf("\nStack Overflow\n");
        return;
    }
    ++top;
    stack[top] = e;
    return;
}
void pop()
{
    if (top == -1)
    {
        printf("%d\n",-1);
        return;
    }
    --top;
    return;
}
int peak()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}
int main()
{
    int p;
    // printf("\nEnter the value of N, k\n");
    int N, K;
    scanf("%d%d", &N, &K);
    int a[N];
    // printf("\nEnter the elements of stack\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p);
        a[N - i - 1] = p;
    }
    for (int i = 0; i < N; i++)
    {
        push(a[i]);
    }

    for (int i = 0; i < N; i++)
    {
    }
    for (int i = 0; i < K; i++)
    {
        if (i == 0)
        {
            p = peak();
            pop();
        }

        if ((peak()) > p)
        {
            p = peak();
            pop();
        }
        else
        {
            push(p);
        }
    }
    if (top == -1)
    {
        printf("%d", -1);
    }
    else
    {
        printf("\n\n%d\n", p);
    }

    return 0;
}