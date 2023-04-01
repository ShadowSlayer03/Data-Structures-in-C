// Finding a pair of elements with sum k for sorted arrays 

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void findPair(int* arr,int sum)
{
  int i=0,j=SIZE-1;
  while(i<j)
    {
      if(arr[i]+arr[j]==sum)
      {
        printf("%d and %d\n",arr[i],arr[j]);
        i++;
        j--;
      }
      else if(arr[i]+arr[j]>sum)
        j--;
      else
        i++;
    }
}
int main()
{
  int k;
  int A[SIZE] = {1,2,3,4,5,6,7,8,9,10};
  printf("Enter the sum of the values:\n");
  scanf("%d",&k);
  findPair(&A[0],k);
  return 0;
}
