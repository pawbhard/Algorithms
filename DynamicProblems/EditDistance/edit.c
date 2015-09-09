
#include<stdio.h>
#include<string.h>

#define QLOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)
#define R 2     //REPLACE 2
#define D 5     //DELETE 5
#define I 4     //INSERT 4

#define min(a,b) (a) > (b) ? (b) : (a)
int Minimum (int a, int b,int c)
{
    return min(min(a,b),c);
}
void print_array(int *editcost ,int  size1 ,int  size2, char *str1, char *str2)
{
    char buffer[1024],buf[30];
    int i , j;

    memset(buffer,0,sizeof(buffer));
    strcpy(buffer,"\t\t");
    for( i = 0 ; i < strlen(str2) ; i++)
    {
            sprintf(buf,"\t%4c",str2[i]);
            strcat(buffer,buf);
    }
    QLOG("%s",buffer);
    for(i = 0; i <= size1; i++)
    {
        memset(buffer,0,sizeof(buffer));
        sprintf(buf,"\t%4c",str1[i-1]);
        strcpy(buffer,buf);
        for( j = 0; j <= size2 ; j++)
        {
            sprintf(buf,"\t%4d",*(editcost+i*(size2+1)+j));
            strcat(buffer,buf);
        }
        QLOG("%s",buffer);
    }
}

int edit(char *str1 ,const int size1 , char *str2,const int size2)
{
    int editcost[size1+1][size2+1];
    memset(editcost, 0, sizeof(editcost)/sizeof(int));

    int i,j,cost;
    //Initial case
    //we have to make str1 to str2
    editcost[0][0] = 0;
    for( i = 1; i <= size1; i++)
    {
        editcost[i][0] = editcost[i-1][0] + D;  //Delete all words 
    }
    for( j = 1; j <= size2; j++)
    {
        editcost[0][j] = editcost[0][j-1] + I;  //Insert all words 
    }
    for(i = 1; i<= size1 ; i++)
    {
        for(j =1; j <= size2 ; j++)
        {
            editcost[i][j] = Minimum ( editcost[i-1][j] + D,                            //insertion
                                       editcost[i][j-1] + I,                            //deletion
                                       editcost[i-1][j-1] + (str1[i-1] != str2[j-1])*R);    //Replacement
        }
    }
     
    print_array((int *)editcost, size1 , size2, str1, str2);
    return editcost[size1][size2];
}

int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        QLOG("Error : not enough arguments");
        QLOG("Usage ./<> str1 str2");
        return 1;
    }
    QLOG("Strings are : %s , %s ",argv[1],argv[2]);
    QLOG("Costs are Insert %d, Replace %d, delete %d",I,R,D);
    printf("Edit distance %d\n",edit(argv[1],strlen(argv[1]),argv[2],strlen(argv[2])));
    return 0;
}


