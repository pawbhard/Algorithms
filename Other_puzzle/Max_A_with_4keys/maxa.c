#include<stdio.h>
#include<math.h>

#define max(a,b) (a) > (b) ? (a) : (b)
int maximum( int x, int y, int z, int w)
{
    return max(x,max(y,max(z,w)));
}
    
int max_a ( int N , int current,int clipboard,int select)
{
    if ( N == 0 )
        return current;;

    //ans for various keys
    int key1 = max_a(N-1,current+1,clipboard,0);                          //A
    int key2 = max_a(N-1,current,(select == 1 ? current: 0),0);       //ctrl + c
    int key3 = max_a(N-1,current+clipboard,clipboard,0);            //ctrl + v
    int key4 = max_a(N-1,current,clipboard,1);                      //ctrl + a

    return maximum(key1,key2,key3,key4);
}
//Using Dynamic programming 
int max_a_dp(const int N)
{
    if(N <= 6) return 6;

    int current[N],cur;
    int i,j;
    for(i = 1; i<=6 ; i++)
    {
        current[i] = i;
    }
    
    for( i = 7 ; i<=N ;i++)
    {
        current[i] = 0;
        for(j = i-3-1; j >1; j--) 
        {
            cur = (i-j-1)* current[j];
            printf(" calculate for %d for j %d  [ %d * %d = %d ]\n"
                            , i,j, N-j-1, current[j], cur); 
            if(cur > current[i] )
                current[i] = cur;
        }
    }
    return current[N];
}


void main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    printf("\nTesting max with 14 2 17 11 = %d\n",maximum(14,2,17,11));
    printf("Maximum A for N = %d is %d\n",N,max_a(N,0,0,0));
    //printf("Maximum A for N = %d is %d\n",N,max_a_dp(N));
}
