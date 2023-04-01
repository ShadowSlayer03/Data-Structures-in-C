// Finding a pair of elements with sum k for sorted and unsorted arrays 
// 1st method: Compare the values by taking 2 for loops.TIME COMPLEXITY- O(n^2)
// 2nd method: By using hash table. TIME COMPLEXITY- O(n)
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void findMax(int* arr,int *max)
{
  int i;
  *max=arr[0];
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]>*max)
        *max = arr[i];
    }
}
void findPair1(int* arr,int sum) 
{
  int i,j;
  for(i=0;i<SIZE;i++)
    {
      for(j=i+1;j<SIZE;j++)
        {
          if(arr[i]+arr[j]==sum)
            printf("%d and %d\n",arr[i],arr[j]);
        }
    }
}
void findPair2(int* arr,int sum)
{
  int* H;
  int max,i;
  findMax(arr,&max);
  H = (int*)calloc(max+1,sizeof(int));
  for(i=0;i<SIZE;i++)
    {
      if(H[sum-arr[i]]>0)
        printf("%d and %d\n",arr[i],sum-arr[i]);
      else
        H[arr[i]]++;
    }
}
int main()
{
  int k;
  int A[SIZE] = {2,3,1,7,8,5,10,4,6,9};
  printf("Enter the sum of the values:\n");
  scanf("%d",&k);
  findPair1(&A[0],k);
  return 0;
}
