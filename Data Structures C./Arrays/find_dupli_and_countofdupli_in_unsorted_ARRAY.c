// Finding duplicates in unsorted array of positive integers
// 1. Hash table
// 2. This method
#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

void findDupli(int* arr)
{
  int i,j,count=1;
  for(i=0;i<SIZE;i++)
    {
     for(j=i+1;j<SIZE;j++)
       {
         if(arr[i]==arr[j] && arr[i]!=-1)
         {
           count++;
           arr[j] = -1;
         }  
       }
      if(count>1)
      printf("%d appears %d times\n",arr[i],count);
      count=1;
    }
}
int main()
{
  int A[SIZE] = {5,4,7,8,8,4,9,4,9,7,8};
  findDupli(&A[0]);
  return 0;
}
