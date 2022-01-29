#include<stdio.h>

int num_pos(int *a, int size)
{
    int temp = -1,ans;
    if(size <= 0)
        return 1;

    if(size >1)
        temp = a[0] * 10 + a[1];

    if(temp > 26)
        temp = -1;
    
   if(temp != -1)
        ans = num_pos(&a[1] , size-1) + num_pos(&a[2], size-2) ;
   else  
       ans = num_pos(&a[1],size-1);
    return  ans;
}

int buffer[1024];
int main()
{
    char str[1024];
    int i;
    char ch;
    scanf("%s",str);
    for(i = 0; str[i] != '\0' ; i++)
    {
        ch = str[i];
        buffer[i]  = atoi(&ch);
    }
    printf("Ans is : %d\n",num_pos(buffer,i));
}


