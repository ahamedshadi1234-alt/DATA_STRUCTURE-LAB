#include <stdio.h>
int main()
{
        int i=1,large=0;
        while(i<=5)
        {
                printf("Enter a number");
                scanf("%d",&num);        
                if (num>large)
                {
                     large=num;
                }
                i=i+1;
        }        
        printf("The largest of 5 numbers is %d\n",large);
}        
