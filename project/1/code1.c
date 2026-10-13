#include<stdio.h>
int delete(int a[],int n,int item)
{
    int m=0;
    for(int i=0;i<n;i++)
        {
            if(a[i]!=item)
               {
                a[m]=a[i];
                m++;
                }
          }
     return m;
 }
 int main()
 {
    int a[100],n,item,t;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    printf("Enter the item to be deleted: ");
    scanf("%d",&item);
    t=delete(a,n,item);
    printf("Array after deletion: ");
    for(int i=0;i<t;i++)
        {
                printf("%d ",a[i]);
        }
    return 0;
 }