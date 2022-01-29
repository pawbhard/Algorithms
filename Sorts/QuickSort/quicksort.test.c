#include<stdio.h>
#include"quicksort.h"
static void test_sort(void) {
    int a[] = { 12,4,66,9,1,11};
    quickSort(0,5,a);
    printf("Sort completed \n");
    for(int i = 0; i < 6;i++)
        printf("%d->",a[i]);
}

int main(void) {
    test_sort();
    printf("\n");
    return 0;
}
