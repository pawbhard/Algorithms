#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<assert.h>
#include"quicksort.h"

#define QUICK_LOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)

void swap (int * num1, int *num2) {
    int t = *num1;
    *num1 = *num2;
    *num2 = t;
}

int divide_array(int l_idx,int h_idx,int *ar) {
    time_t t;
    srand((unsigned) time(&t));
    int pivot = l_idx + rand() % (h_idx - l_idx + 1);
    int pv_data = ar[pivot];
    swap(&ar[pivot], &ar[h_idx]);
    int pv_idx = h_idx;
    int i = l_idx -1;
    for (int j = l_idx; j < h_idx; j++) {
        if(ar[j] <= pv_data) {
            i++;
            swap(&ar[i],&ar[j]);
        }
    }
    swap(&ar[i+1],&ar[pv_idx]);
    return i+1;
}

void quickSort(int l_idx,int h_idx,int *a) {
    if(l_idx < h_idx) {
        int p = divide_array(l_idx,h_idx,a);
        quickSort(l_idx , p-1 , a);
        quickSort(p+1 ,h_idx, a);
    }
}

