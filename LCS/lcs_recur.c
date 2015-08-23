#include<stdio.h>
#include<string.h>

#define MAX(a,b)  (a) > (b) ? (a) : (b)
int lsc_rec(char *a, char *b, int sz_a, int sz_b)
{
    if(sz_a == -1 || sz_b == -1)
        return 0;

    if(a[sz_a] == b[sz_b]) {
        return 1 + lsc_rec(a,b,sz_a-1,sz_b-1);
    } else {
        return MAX(lsc_rec(a,b,sz_a-1,sz_b),lsc_rec(a,b,sz_a,sz_b-1));
    }
}

void main(int argc, char *argv[])
{
    char a[1024],b[1024];

    if(argc >= 3)   {
        strcpy(a,argv[1]);
        strcpy(b,argv[2]);
    } else {
        printf("Error Usage ./<> str1 str2 %d\n",argc);
        return;
    }
    int sz_a = strlen(a) - 1;
    int sz_b = strlen(b) - 1;

    printf("LCS length is %d\n",lsc_rec(a,b,sz_a,sz_b));
}
