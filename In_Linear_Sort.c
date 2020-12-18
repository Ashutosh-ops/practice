#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n)
{
    size_t i = 0;
    for (; i < n; i++)
    {
        printf("%d\t", *(a + i));
    }
    printf("\n");
    return;
}

void cycle_Sort(int* a, int n)
{
    signed long i = 0;
    for (;i < n;)
    {
        if ((*(a+i)) == i+1)
        {
            i++;
        }
        else
        {
            (*(a+i)) = ((*(a+((*(a+1))-1))) + (*(a+i)))-((*(a+((*(a+1))-1))) = (*(a+i)));
        }
    }
    // for (int i = 0; i < n;)
    // {

    //     // If the current element is
    //     // at correct position
    //     if (a[i] == i + 1)
    //     {
    //         i++;
    //     }

    //     // Else swap the current element
    //     // with it's correct position
    //     else
    //     {
    //         // swap(&a[i], &a[a[i] - 1]);
    //         a[a[i]-1] = a[a[i]-1] + a[i] - (a[i]=a[a[i]-1]);
    //     }
    // }
}

int main(int argc, char const *argv[])
{
    int n;
    size_t i = 0;
    printf("\nEnter the length of the array: ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    printf("Enter the elements :");
    for (; i < n; i++)
    {
        scanf("%d",(arr+i));
    }
    printf("\n\nBefore the cycle_Sort\n\n");
    print_array(arr, n);
    cycle_Sort(arr, n*4);
    printf("\n\nAfter the cycle_Sort\n\n");
    print_array(arr, n);
    free(arr);
    return 0;
}
