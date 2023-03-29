// Find multiple missing elements in a sorted array(array elements start randomly or from 1)

#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

void FindMissing(int* arr)
{
  int i,diff,x;
  diff = arr[0]-0;
  
  for(i=0;i<SIZE;i++)
    {
      x = arr[i]-i;
      if(x!=diff)
      {
        while(x>diff)
          {
             printf("%d ",i+diff);
             diff++;
          }
      }
    }
}
int main()
{
  int A[SIZE] = {11,13,16,17,20,21};
  FindMissing(&A[0]);
  return 0;
}
