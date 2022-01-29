#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<assert.h>
#include"mergesort.h"

#define QUICK_LOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)

void merge_array(int *ar1 , int size1, int *ar2, int size2) {
    int i = 0, j = 0, k = 0;
    int *ar3 = (int *) malloc( (size1 + size2)* sizeof(int));
    while( (i < size1) && (j < size2)) {
        if(ar1[i] <= ar2[j])
            ar3[k++] = ar1[i++];
        else
            ar3[k++] = ar2[j++];
    }

    if ( i < size1)
    {
        while(i < size1)
            ar3[k++] = ar1[i++];
    }
    if (j < size2)
    {
        while(j < size2)
            ar3[k++] = ar2[j++];
    }

    //copy array to ar1
    for(int x = 0; x< k; x++)
        ar1[x] = ar3[x];
    free(ar3);
}

void mergesort(int *ar, int size)
{
    if(size <= 1)
        return;
    int mid = size/2;
//    QUICK_LOG("Mid is %d",mid);
    mergesort(ar, mid);
    mergesort(ar+mid, size-mid);
    merge_array(ar,mid,ar+mid,size-mid);
}
