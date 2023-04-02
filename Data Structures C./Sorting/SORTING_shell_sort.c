// Shell Sort is just a different version of insertion sort.
// It makes use of the fact that if some swaps or comparisons are already made in the form of passes, then the overall process of sorting is easier, and the no of comparisons in each pass is negligible.
#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

void swap(int* a,int* b)
{
  int temp;
  temp= *a;
  *a=*b;
  *b=temp;
}
void ShellSort(int* arr)
{
  int temp,i,j,k;
  int gap = SIZE/2;
  while(gap>=1)
    {
      for(i=gap;i<SIZE;i++)
        {
          j=i-gap;
          temp = arr[i];
          while(temp<arr[j] && j>=0)
            {
              arr[j+gap]=arr[j];
              j=j-gap;
            }
          arr[j+gap]=temp;
        }
      gap = gap/2;
    }
}
void printArr(int* arr)
{
  int i;
  for(i=0;i<SIZE;i++)
    {
      printf("%d ",arr[i]);
    }
}
int main()
{
  int A[SIZE]={23,56,45,78,90,94,33,1,15,43,67};
  ShellSort(&A[0]);
  printArr(&A[0]);
  return 0;
}
