#include<stdio.h>
#include<string.h>

#define Q_LOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)

#define MAX(a,b)  (a) > (b) ? (a) : (b)
int lsc_rec(char *a, char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    //int *mem;
    int sz_a,sz_b;
    int mem[1024][1024] = {0};
    //we will use this as row wise
    //mem = (int *) malloc(sizof(int)*(sz_a+1)*(sz_b+1));
    //index will be considered as -1 to strlen(a)-1
    //if(sz_a == -1 || sz_b == -1)
    //    return 0;
    mem[0][0] = mem[0][1] = mem[1][0] = 0;
    for(sz_a = 1; sz_a < len_a ; sz_a++) 
    {
        for(sz_b = 1; sz_b <= sz_a && sz_b < len_b; sz_b++ )
        {
            Q_LOG("Doing for [%d][%d] using [%d][%d] , [%d][%d] and [%d][%d] ",
                    sz_a,sz_b , sz_a-1,sz_b-1,sz_a-1,sz_b,sz_a,sz_b-1);
            if(a[sz_a] == b[sz_b]) {
                //return 1 + lsc_rec(a,b,sz_a-1,sz_b-1);
                mem[sz_a][sz_b] = 1 + mem[sz_a - 1][sz_b-1];
            } else {
                //return MAX(lsc_rec(a,b,sz_a-1,sz_b),lsc_rec(a,b,sz_a,sz_b-1));
                mem[sz_a][sz_b] = MAX(mem[sz_a-1][sz_b] , mem[sz_a][sz_b-1]);
            }
        }
    }

    Q_LOG("Printing matrix\n");
    
    for(sz_b = -1; sz_b <len_b ; sz_b++)
    {
        if(sz_b == -1) printf(" \t");
        else printf("%c\t",b[sz_b]);
    }
    printf("\n");
    for(sz_a = 0 ; sz_a <len_a; sz_a++)
    {
        for(sz_b = -1; sz_b <len_b ; sz_b++)
        {
            if(sz_b == -1)
                printf("%c\t",a[sz_a]);
            else
                printf("%d\t",mem[sz_a][sz_b]);
        }
        printf("\n");
    }
    printf("\n");
    return mem[len_a-1][len_b-1];
}

void main(int argc, char *argv[])
{
    char a[1024],b[1024];

    if(argc >= 3)   {
        strcpy(a,argv[1]);
        strcpy(b,argv[2]);
    } else {
        Q_LOG("Error Usage ./<> str1 str2 %d\n",argc);
        return;
    }
    Q_LOG("LCS length is %d\n",lsc_rec(a,b));
}
