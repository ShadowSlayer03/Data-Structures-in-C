//Count sort- Makes a count table which works exactly like a hash table and finally all the elements(>0) from the count table are decremented and their indices are pushed to the initial array in sorted manner
// TIME COMPLEXITY - O(n) 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int maximum(int* arr)
{
  int max=0,i;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]>max)
        max=arr[i];
    }
  return max;
}
void CountSort(int* arr)
{
  int max = maximum(&arr[0]);
  int j=0,i;
  int* count = (int*)calloc(max+1,sizeof(int));  //max+1 array with all elements 0
  for(i=0;i<SIZE;i++)
    {
      count[arr[i]]++;
    }
  for(i=0;i<=max;i++)
    {
      while(count[i]>0)
        {
          arr[j]=i;
          j++;
          count[i]--;
        }
    }
  free(count);
}
void printArr(int* arr)
{
  int i;
  for(i=0;i<SIZE;i++)
    printf("%d ",arr[i]);
}
int main()
{
  int array[SIZE]={1,6,7,34,98,2,15,78,67,90};
  CountSort(&array[0]);
  printArr(&array[0]);
  return 0;
}
