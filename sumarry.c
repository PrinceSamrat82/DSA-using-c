#include<stdio.h>
#include<math.h>
int main()
{
 int a[5];
 int i,sum=0;
 printf("Enter the elements of array :-\n");
 for(i=0;i<4;i++)
 { 
     scanf("%d",&a[i]);
 }
 for(i=0;i<4;i++)
    {
     sum=sum+a[i];
    }
 printf("summation of all elements of array :-\n");
 printf("%d\t",sum);
 return 0;
}