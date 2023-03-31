// Finding dupli elements and count of dupli using hash table for a sorted array or unsorted array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
void findMinMax(int* arr,int* max,int* min)
{
  int i;
  *max=*min=arr[0];
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]>*max)
        *max = arr[i];
      if(arr[i]<*min)
        *min = arr[i];
    }
}
void FindandCount_Dupli(int* arr)
{
  int* H;
  int max,min,i;
  findMinMax(arr,&max,&min);
  H = (int*)calloc(max+1,sizeof(int));
  for(i=0;i<SIZE;i++)
    {
      H[arr[i]]++;
    }
  for(i=min;i<=max;i++)
    {
      if(H[i]>1)
      {
        printf("%d occurred %d times.\n",i,H[i]);
      }
    }
}
int main()
{
  int A[SIZE] = {1,1,2,3,4,4,4,5,6,6,6,6,7,7,7,7,7,7,7,7};
  FindandCount_Dupli(&A[0]);
  return 0;
}
