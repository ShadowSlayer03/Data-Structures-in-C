#include<stdio.h>
#include<stdlib.h>

int isSorted(int* arr,int length)
{
  int i;
  for(i=0;i<length;i++)
    {
      if(arr[i]>arr[i+1])
        return 0;
    }
  return 1;
}
void InsertSorted(int* arr,int x,int length)
{
  int i;
  for(i=length-1;arr[i]>x;i--)
    {
      arr[i+1] = arr[i];
    }
  arr[i+1] = x;
}
void printArr(int* arr,int length)
{
  int i;
  for(i=0;i<length;i++)
    {
      printf("%d ",arr[i]);
    }
}
int main()
{
  int A[11] = {1,2,3,4,5,6,9,10,11,90};
  // if(isSorted(&A[0],10))
  //   printf("Array is sorted\n");
  // else
  //   printf("Array is not sorted\n");
  // InsertSorted(&A[0],23,10);
  // printArr(&A[0],11);
  return 0;
}
