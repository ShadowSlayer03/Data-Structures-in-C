// Finding duplicates and no of duplicates in a sorted array
// to find count of dupli, when both arr[i] and arr[i+1] are equal, take j=i+1 and until arr[i]==arr[j] keep incrementing j. Then count = j-i. In order to stop the same element from appearing many times, use prevDupli.
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void findDupli(int* arr)
{
  int i,prevDupli=0;
  for(i=0;i<SIZE;i++)
  {
    if(arr[i+1]==arr[i] && arr[i+1]!=prevDupli)
    {
      printf("%d is a duplicate element\n",arr[i]);
      prevDupli=arr[i];
    }
  }
}
void countDupli(int* arr)
{
  int i,j,prevDupli=0;
  for(i=0;i<SIZE-1;i++)
    {
      if(arr[i]==arr[i+1] && arr[i+1]!=prevDupli)
      {
        j = i+1;
        while(arr[i]==arr[j]) j++;
        printf("%d occurs %d times\n",arr[i],j-i);
        prevDupli = arr[i];
      }
    }
}
int main()
{
  int A[SIZE] = {2,2,3,6,6,6,6,8,8,8};
  //findDupli(&A[0]);
  countDupli(&A[0]);
  return 0;
}
