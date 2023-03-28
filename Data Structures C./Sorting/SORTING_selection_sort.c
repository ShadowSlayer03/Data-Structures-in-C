// It is called selection sort because smallest element is selected in each pass and pushed to the front of the array.
#include<stdio.h>
#define SIZE 7

void swap(int* a,int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void SelectionSort(int arr[])
{
  int i,j,k;
  for(i=0;i<SIZE;i++)
    {
      for(j=k=i;j<SIZE;j++)
        {
          if(arr[j]<arr[k])
            k = j;
        }
      swap(&arr[k],&arr[i]);
    }
}
int main()
{
  int i;
  int A[SIZE] = {23,5,67,89,90,4,54};
  SelectionSort(A);
  for(i=0;i<SIZE;i++)
    {
      printf("%d ",A[i]);
    }
  return 0;
}
