#include<stdio.h>

int main()
{
  int a[5],b[5];

    printf("enter 1st array\n");
    for (int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("enter 2nd array\n");
    for (int i=0;i<5;i++)
    {
        scanf("%d",&b[i]);
    }

    printf("sum of two array is: \n");
    for(int i=0; i<5; i++)
    {
        printf("%d\t",a[i]+b[i]);
    }

    return 0;
}