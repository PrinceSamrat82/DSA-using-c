#include<stdio.h>
#include<math.h>
#define max_size 101
#define swap(x,y,t)((t) = (x),(x) = (y) = (t))
int sort(int[],int);
int main()
{
 int i,n;
 int list[max_size],rand;
 printf("enter the number to generate:");
 scanf("%d",&n);
 if(n<1||n>max_size)
 {
 printf("improper value ofn\n",stderr);
 
 }
 
 for(i=0; i<n; i++)
 {
 list[i]=rand%1000;
 printf("%d",list[i]);


 sort(list,n);
 printf("\n sorted array:\n");
 }
 for(i=0;i<n;i++)
 {
 printf("%d",list[i]);
 printf("\n");
 }
int sort(int[], int n);
{
 int i,j,min,temp;
 for(i=0; i<n-1; i++)
 {
  min=i;
  for(j=i+1; j<n; j++)
  if(list[j]< list[min])
  min=j;
  swap(list[i], list[min],temp);
 }
}

}
