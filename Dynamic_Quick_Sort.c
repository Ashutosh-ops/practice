#include <stdio.h>
#include <stdlib.h>

void print_Array(int *a,int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t", *(a + i));
    }
    printf("\n");
    return;
}

int breaker_fun(int *a, int low, int high)
{
    int i = low + 1, j = high, pivot = (*(a + low));
    do
    {
        while ((*(a + i)) <= (*(a + low)))
            i++;
        while ((*(a + j)) > (*(a + low)))
            j--;
        if (i < j)
            (*(a + j)) = (((*(a + j))) + ((*(a + i)))) - ((*(a + i)) = (*(a + j)));
    } while (i < j);
    (*(a + j)) = (((*(a + j)) + (*(a + low))) - ((*(a + low)) = (*(a + j))));
    return j;
}

void Quick_Sort(int *a, int low, int high)
{
    if (low < high)
    {
        int breaker = breaker_fun(a, low, high);
        Quick_Sort(a, low, breaker - 1);
        Quick_Sort(a, breaker + 1, high);
    }
    return;
}

int main(int argc, char const **argv)
{
    int n, *a;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    printf("\n");
    a = (int *)calloc(n, sizeof(int));
    printf("Enter the elements :");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", (a + i));
    }
    // *(a + n) = "\0";
    printf("\nBefore the quick sort: \n");
    print_Array(a, n);
    Quick_Sort(a, 0, n - 1);
    printf("\nAfter the quick sort: \n");
    print_Array(a,n);
    free(a);
    return 0;
}
