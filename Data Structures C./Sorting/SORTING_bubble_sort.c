#include<stdio.h>
#define SIZE 8

void swap(int* a,int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void BubbleSort(int arr[])
{
  int i,j,flag;
  for(i=0;i<SIZE-1;i++)
    {
      flag=0;
      for(j=0;j<SIZE-i-1;j++)
        {
          if(arr[j]>arr[j+1])
          {
            swap(&arr[j],&arr[j+1]);
            flag=1;
          }
        }
      if(flag==0)
        break;
    }
}
int main()
{
  int k;
  int arr[] = {2,67,34,90,87,4,1,45};
  BubbleSort(arr);
  for(k=0;k<SIZE;k++)
    printf("%d ",arr[k]);
  return 0;
}
