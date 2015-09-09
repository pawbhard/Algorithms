/* find minimum cost path for a 2 d array from 0,0 to m,n
*/
#include<stdio.h>
#include <limits.h>
#include<stdlib.h>

#define row 5
#define col 5
#define min(a,b) (a)>(b)?(b):(a)
//Recursive
int minimum(int a, int b, int c)
{
    if( a > b)
        return b > c ? c : b;
    else
        return a > c ? c : a;
}
int path_recur(int ar[row][col], int i,int j)
{
    if( row-1 == i && col-1 == j)
        return ar[i][j];

    int right  = (j+1) >= col ? INT_MAX : (ar[i][j] + path_recur(ar,i,j+1)); 
    int down  = (i+1) >= row ? INT_MAX : (ar[i][j] + path_recur(ar,i+1,j)); 
    int diag = ((i+1) >= row || (j+1) >= col ) ? INT_MAX : ar[i][j] + path_recur(ar,i+1,j+1);
    return min(min(right,down),diag);
}

int path_dp(int arr[row][col])
{
    int cost[row][col]; //cost to reach that point 

    int i,j;
    cost[0][0] = arr[0][0];
    printf("%d 00000",cost[0][0]);
    for( i = 1; i < row; i++)
        cost[i][0] = cost[i-1][0] + arr[i][0];
    for( j = 0; j <col ; j++)
        cost[0][j] = cost[0][j-1] + arr[0][j];
    for( i = 1; i < row; i++)
    {
        for( j = 1; j <col ; j++)
        {
            printf("\nSelect from %d(%d,%d) ,  %d(%d,%d) and  %d(%d,%d)  addding %d ",
                   cost[i-1][j],i-1,j,cost[i][j-1],i,j-1, cost[i-1][j-1] , i-1,j-1, arr[i][j]);
            cost[i][j] = arr[i][j] + minimum(cost[i-1][j],cost[i][j-1],cost[i-1][j-1]);
            printf("\ncost[%d][%d] = %d",i,j,cost[i][j]);
        }
    }
    
    printf("\nPrinting array\n");
    for( i = 0; i < row; i++)
    {
        for( j = 0; j <col ; j++)
           printf("\t%d",cost[i][j]);
        printf("\n");
    }

    return cost[row-1][col-1];
}

int main()
{
    int arr[row][col];
    int i,j;

    for( i = 0 ; i < row ;i++)
        for(j = 0 ; j < col ; j++)
            scanf("%d",&arr[i][j]);

    printf("\nMinimum path is %d\n",path_dp (arr));

   return 0;
}
