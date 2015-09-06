#include<stdio.h>
#include<limits.h>

#define INF INT_MAX
#define QLOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)
int power(int x, int y)
{
    // x raised to power y
    if(y == 0) return 1;
    if(y == 1) return x;
    
    int ans = power(x,y/2);
    ans *= ans  ;
    if(x & 1)
        ans *= x; 
    return ans;
}
int printSolution (int p[], int n)
{
    int k;
    if (p[n] == 0)
        k = 0;
    else
        k = printSolution (p, p[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    return k;
}
void justify(int *w,const int size, const int lw)
{   
    int c[size],space[size][size];
    int ans[size];
    QLOG("lw is %d ",lw);
    int i,j;
    //find space in line if i to j words are filled in line
    for(i = 0 ; i < size; i++)
    {   space[i][i] = lw - w[i];
        QLOG("space for %d to %d is %d",i,i,space[i][i]);
        for( j = i+1; j < size;j++)
        {   space[i][j] = space[i][j-1] - w[j] - 1;
            QLOG("space for %d to %d is %d",i,j,space[i][j]);
        }
    }
    
    //convert space to cost 
    for(i = 0; i< size; i++)
    {
        for(j =i; j < size ; j++)
        {
            if(space[i][j] >= 0 )
                space[i][j] = power(space[i][j],3);
            else 
                space[i][j] = INF;
        }
    }

    
    //print
    for( i = 0 ; i<size; i++)
    {
        for(j = i; j < size; j++)
            printf("%d\t\t",space[i][j]);
        printf("\n");
    }   
    
    /* 
    *             {  0   if j = 0
    *   cost[j] = {    min      (c[i-1] + space[i][j])
    *             { 1<= i <= j
    */

    c[0] = 0;
    for( j = 1; j < size ; j++)
    {   c[j] = INF;
        for( i = 0; i <= j ; i++) 
        {
            if(c[i-1] != INF && space[i][j] != INF && (c[i-1]+space[i][j]) < c[j])
            {
                c[j] = c[i-1]+space[i][j];
                ans[j] = i;
            }
        }
    }
    printf("\n");
    printSolution(ans,size-1);
}



void main()
{
    int i,w[] = { 2,3,4,1,2,2 };
    for(i = 0; i < 5; i++)
        QLOG("Word sizes : %d",w[i]);
    justify(w,5,8);
}

