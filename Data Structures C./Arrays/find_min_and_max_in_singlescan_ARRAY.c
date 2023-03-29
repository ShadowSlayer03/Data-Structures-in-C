// Finding min and max element of an array in a single scan
#include<stdio.h>
#include<stdlib.h>
#define size 6

void findMinMax(int* arr,int* min,int* max)
{
  int i; 
  *min=*max=arr[0];
  for(i=0;i<size;i++)
    {
      if(arr[i]<*min)
        *min = arr[i];
      if(arr[i]>*max)
        *max = arr[i];
    }
}
int main()
{
  int A[size]={1,34,7,23,5,12};
  int min,max;
  findMinMax(&A[0],&min,&max);
  printf("The minimum element is %d and maximum element is %d",min,max);
  return 0;
}
