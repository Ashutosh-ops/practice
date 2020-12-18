#include "bits/stdc++.h"
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
}
void sortArray(int arr[], int N)
{
    for (int i = 0; i < N;) {
        if (arr[i] == i + 1) {
            i++;
        }
        else {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }
}

int main()
{
    int n;
    cout <<"Enter the length of the array: ";
    cin>>n;
    cout <<"Enter the elements: ";
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int N = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i<N; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout <<sizeof(arr)<<endl;
    sortArray(arr, N);
    printArray(arr, N);
    return 0;
}