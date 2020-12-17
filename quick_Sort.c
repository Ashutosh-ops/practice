#include <stdio.h>
#include <stdlib.h>
void print_Array(int *a,int n)
{
    for (size_t i = 0; i<n; i++)
        printf("%d\t", *(a + i));
    printf("\n");
    return;
}
void Quick_Sort(int *a, int begin, int end_edge)
{
    if (begin < end_edge)
    {
        int i = begin + 1, j = end_edge;
        do
        {
            while ((*(a + i)) <= (*(a + begin)))
                i++;
            while ((*(a + j)) > (*(a + begin)))
                j--;
            if (i < j)
                (*(a + j)) = (((*(a + j))) + ((*(a + i)))) - ((*(a + i)) = (*(a + j)));

        } while (i < j);
        (*(a + j)) = (((*(a + j)) + (*(a + begin))) - ((*(a + begin)) = (*(a + j))));
        int p_index = j;
        Quick_Sort(a, begin, p_index - 1);
        Quick_Sort(a, p_index + 1, end_edge);
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
    printf("\nBefore the quick sort: \n");
    print_Array(a,n);
    Quick_Sort(a, 0, n - 1);
    printf("\nAfter the quick sort: \n");
    print_Array(a,n);
    free(a);
    return 0;
}
