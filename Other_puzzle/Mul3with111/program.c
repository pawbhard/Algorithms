#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mul_3[] = { 0,  // 3*0 = 0
                7,  // 3 * 7 = 21
                4,
                1,
                8,
                5,
                2,
                9,
                6,
                3,
};
int is_contain_one_only(int n)
{
    if(n == 0)
        return 1;
    while(n)
    {
        if(n % 10 != 1)
            return 0;
        n /= 10;
    }
    return 1;
}

void main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage program <number>\n");
        return;
    }

    int num = atoi(argv[1]);
    printf("Number is %d\n",num);

    char *ans; //[1024] = "";
    ans = (char *) malloc(1000000*sizeof(char));
    ans[0] =  '\0';
    int carry = 0; 
    int multiply_ans = 0;
    int multiply_by = 7;
    while(1)
    {   printf("Ans is %s\n",ans);
        multiply_ans = num * multiply_by + carry;
        strcat(ans,"1");
        carry = multiply_ans / 10;
        if(is_contain_one_only(carry) )
        {
            if(carry != 0)
            {
                while(carry)
                {
                    if(carry %10 == 1)
                        strcat(ans,"1");
                    carry /= 10;
                }
            }
            break;
        }
        multiply_by = mul_3[11 - (carry  % 10)];
    }
    printf("Ans is %s of length %d\n", ans, strlen(ans));
}
