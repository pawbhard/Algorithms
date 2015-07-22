#include<stdio.h>
#include"mergesort.h"
static void test_sort(void) {
    int a[] = { 12,4,66,9,1,11};
    mergesort(a,6);
    printf("Sort completed \n");
    for(int i = 0; i < 6;i++)
        printf("%d->",a[i]);
    printf("\n");
    int b[] = { -12,4,-66,9,1,11,8};
    mergesort(b,7);
    printf("Sort completed \n");
    for(int i = 0; i < 7;i++)
        printf("%d->",b[i]);
}

int main(void) {
    test_sort();
    printf("\n");
    return 0;
}
