#include<string.h>
#include<stdio.h>
#define QLOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)
int get_lis(const int *ar ,const  int size)
{
    /* O(n^2) complexity DP solution */   
    
    int lis[size];
    int i, j;
    QLOG("Size is %d",size);
    //init with 1
    for (i = 0; i < size ; i++)
    {
        lis[i] = 1;
    }
    
    QLOG("Element 0 : %d ",ar[0]);
    for(i = 1; i < size; i++)
    {
        QLOG("Element %d : %d ",i ,ar[i]);
        for(j = 0; j < i; j++)
        {
            if(ar[i] > ar[j] && lis[i] < lis[j] + 1)
            {
                QLOG("Updating lis[%d] to lis[%d] + 1 = %d",i,j,lis[j]+1);
                lis[i] = lis[j] +1;
            }
        }
    }

    //find maximum
    int max = lis[0];
    for(i = 1; i < size; i++)
    {
        if(max < lis[i])
            max = lis[i];
    }
    return max;
}

int get_ceilindex(int *ar,int l,int r, int k)
{
    int m;
    while(r-l > 1)
    {
        m = l + ( r - l ) / 2 ;
        
        if(ar[m] >= k)
            r = m;
        else 
            l = m;
    }

    return r;
}
void print_array(int a[], const int size)
{
    char buffer[1024],buf[30];
    snprintf(buffer,1024,"Printing array : ");
    int i;
    for(i = 0; i < size; i++)
    {
        snprintf(buf,30,"  %3d",a[i]);
        strncat(buffer,buf,30);
    }
    QLOG("%s",buffer);
}

int get_lis_optimize(int ar[], const int size)
{
    int tailTable[size];
    int i,len = 1;
    for(i = 0; i < size; i++)
        tailTable[i] = 0;
    print_array(ar,size);
    tailTable[0] = ar[0];
    for(i = 1; i < size; i++)
    {
        if(tailTable[0] > ar[i])
            tailTable[0] = ar[i];
        else if (tailTable[len-1] < ar[i])
            tailTable[len++] = ar[i];
        else
            tailTable[get_ceilindex(tailTable,-1,len-1,ar[i])] = ar[i];
        print_array(tailTable, sizeof(tailTable)/sizeof(tailTable[0]));
    }

    return len;
}


int main(void)
{
    //int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int arr[] = { 10, 22, 9, 13, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", get_lis( arr, n ) );
    printf("Length of LIS is %d\n", get_lis_optimize( arr, n ) );
    return 0;
}
