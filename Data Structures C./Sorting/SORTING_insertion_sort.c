#include<stdio.h>
#define SIZE 7

void Insertion(int arr[])
{
  int i,x,j;
  for(i=1;i<SIZE;i++)
    {
      x = arr[i];
      j = i-1;
      while(j>-1 && arr[j]>x)
        {
          arr[j+1] = arr[j];
          j--;
        }
      arr[j+1] =x;
    }
}
int main()
{
  int arr[SIZE] = {34,5,23,7,67,90,6};
  Insertion(arr);
  int i;
  for(i=0;i<SIZE;i++)
    {
      printf("%d ",arr[i]);
    }
  return 0;
}
