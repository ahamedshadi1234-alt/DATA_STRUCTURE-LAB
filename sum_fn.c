#include<stdio.h>
int add(int,int);
int add (int x,int y)
{
         int result;
         result=x+y;
         return (result);
}

int main()
{
        int n1,n2,result;
        printf("Enter the first number ");
        scanf("%d",&n1);
        printf("Enter the second number ");
        scanf("%d",&n2);
        result=add(n1,n2);
        printf("Result of Addition is %d\n",result);
        return(0);
        }
        



