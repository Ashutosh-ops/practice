#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int N)
{
 
    // Traverse the array
    for (int i = 0; i < N; i++) {
        // cout << arr[i] << ' ';
        printf("%d ",arr[i]);
    }
}
void sortArray(int arr[], int N)
{
 
    // Traverse the array
    for (int i = 0; i < N;) {
 
        // If the current element is
        // at correct position
        if (arr[i] == i + 1) {
            i++;
        }
 
        // Else swap the current element
        // with it's correct position
        else {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }
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
    // n*=sizeof(int);
    printf("\n\nBefore the cycle_Sort\n\n");
    printArray(arr, n);
    sortArray(arr, n);
    printf("\n\nAfter the cycle_Sort\n\n");
    printArray(arr, n);
    free(arr);
    return 0;
}
