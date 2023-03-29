// Find multiple missing elements in a sorted or unsorted array (min element is 1) by hash table
#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

int findMax(int* arr)
{
  int max=arr[0],i;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]>max)
        max = arr[i];
    }
  return max;
}
int findMin(int* arr)
{
  int min=arr[0],i;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]<min)
        min = arr[i];
    }
  return min;
}
void findMissing(int* arr)
{
  int max = findMax(arr);
  int min = findMin(arr);
  int* B,i;
  B = (int*)calloc((max+1),sizeof(int));
  for(i=0;i<SIZE;i++)
    {
      B[arr[i]]++;
    }
   for(i=min;i<max+1;i++)
    {
      if(B[i]==0)
        printf("%d is not present in the array\n",i);
    }
}
int main()
{
  int A[SIZE] = {10,1,2,3,6,8,15,13,16,18,19};
  findMissing(&A[0]);
  return 0;
}
