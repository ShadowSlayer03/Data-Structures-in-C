// Set operations - union, intersection and difference
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int* Union(int* arr1,int* arr2)
  {
    int i=0,k=0,t=0,flag;
    int* arr3;
    arr3 = (int*)malloc(sizeof(int)*(2*SIZE));
    for(i=0;i<SIZE;i++)
      {
        arr3[k++] = arr1[i];
      }
    for(i=0;i<SIZE;i++)
      {
        for(t=0;t<=k;t++)
          {
            if(arr2[i]==arr3[t])
            {
              flag=1;
              break;
            }
            else
            {
              flag=0;
              continue;
            }
          }
        if(flag)
          continue;
        else
          arr3[k++] = arr2[i];
      }
    return arr3;
  }
int* Intersection(int* arr1,int* arr2)
{
  int i,j,k=0,flag;
  int* arr3 = (int*)malloc(sizeof(int)*SIZE);
  for(i=0;i<SIZE;i++)
    {
      for(j=0;j<SIZE;j++)
        {
          if(arr1[i]==arr2[j])
          {
            flag = 1;
            break;
          }
          else
          {
            flag =0;
            continue;
          }
        }
      if(flag)
        arr3[k++] = arr1[i];
    }
  return arr3;
}
int* Difference(int* arr1,int* arr2)
{
  int i,j,k=0,flag;
  int* arr3 = (int*)malloc(SIZE*sizeof(int));
  for(i=0;i<SIZE;i++)
    {
      for(j=0;j<SIZE;j++)
        {
          if(arr1[i]!=arr2[j])
          {
            flag =0;
            continue;
          }
          else
          { 
            flag=1;
            break;
          }
        }
      if(!flag)
        arr3[k++] = arr1[i];
    }
  return arr3;
}
void printArr(int* arr,int size)
{
  int i;
  for(i=0;i<size;i++)
    {
      printf("%d ",arr[i]);
    }
}
int main()
{
  int A[SIZE] = {1,9,78,49,5};
  int B[SIZE] = {34,4,9,87,57};
  // int* res = Union(&A[0], &B[0]);
  // printArr(res,2*SIZE);
  // int* res = Intersection(&A[0], &B[0]);
  // printArr(res,SIZE);
  int* res = Difference(&A[0], &B[0]);
  printArr(res,SIZE);
  return 0;
}
