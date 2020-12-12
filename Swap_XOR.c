#include <stdio.h>

int main() {
    int i, k;
    printf("\nEnter two numbers: ");
    scanf("%d%d", &i, &k);
    printf("\nBefore swapping: i=%d k=%d.\n", i, k);
    i^=(k^=(i^=k));
    printf("\nAfter swapping: i=%d k=%d.\n", i, k);
    return 0;
}