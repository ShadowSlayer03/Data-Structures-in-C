// In a jumbled array of negative and positive numbers, we need to bring all negatives on one side and positives on the other side
// all positives will be on left side and all negatives on right side
#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b)
{
int temp;
  temp =*a;
  *a = *b;
  *b = temp;
}
void SplitNegandPos(int* arr,int length)
{
 int i=0,j=length-1;
  while(i<j)
    {
      while(arr[i]>0)
        i++;
      while(arr[j]<0)
        j--;
      
      swap(&arr[i],&arr[j]);
    }
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
  int A[11] = {1,-2,3,4,-5,-6,9,-10,-11,-90};
  // if(isSorted(&A[0],10))
  //   printf("Array is sorted\n");
  // else
  //   printf("Array is not sorted\n");
  // InsertSorted(&A[0],23,10);
  // printArr(&A[0],11);
  SplitNegandPos(&A[0],11);
  printArr(&A[0], 11);
  return 0;
}
