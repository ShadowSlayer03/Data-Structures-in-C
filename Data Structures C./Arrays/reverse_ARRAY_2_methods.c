#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void ReverseArray1(int* arr) // Reverse array with extra array
{
  int i,j,B[SIZE];
  for(i=SIZE-1,j=0;i>=0;i--,j++)
    {
      B[j] = arr[i];
    }
  for(i=0;i<SIZE;i++)
    {
      arr[i] = B[i];
    }
}
void ReverseArray2(int* arr)  //Revrse array without extra array
{
  int i,temp;
  for(i=0;i<SIZE/2;i++)
    {
      temp = arr[i];
      arr[i] = arr[SIZE-i-1];
      arr[SIZE-i-1] = temp;
    }
}
void printArr(int* arr)
{
  int i;
  for(i=0;i<SIZE;i++)
    {
      printf("%d ",arr[i]);
    }
  printf("\n");
}
int main()
{
  int A[SIZE]={1,2,3,4,5,6,7,8,9,10};
  printArr(&A[0]);
  // ReverseArray1(&A[0]);
  // printArr(&A[0]);  
  ReverseArray2(&A[0]);
  printArr(&A[0]);
  return 0;
}
