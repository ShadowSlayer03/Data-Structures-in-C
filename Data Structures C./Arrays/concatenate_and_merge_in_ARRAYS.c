// MERGE - 2 sorted arrays should be made into a single sorted array
// CONCATENATE - One array added to the end of the other
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int *concatenate(int *arr1, int *arr2) {
  int i, j;
  int *C;
  C = (int *)malloc(sizeof(int) * (2 * SIZE));
  for (i = 0; i < SIZE; i++) {
    C[i] = arr1[i];
  }
  for (j = 0; j < SIZE; j++, i++) {
    C[i] = arr2[j];
  }
  return C;
}
int* merge(int *arr1, int *arr2,int l1,int l2) 
{
  int i=0,j=0,k=0;
  int* arr3;
  arr3 = (int*)malloc(sizeof(int)*(l1+l2));
  while(i<l1 && j<l2)
    {
      if(arr1[i]<arr2[j])
        arr3[k++] = arr1[i++];
      else if(arr1[i]>arr2[j])
         arr3[k++] = arr2[j++];
      else
      { 
        arr3[k++] = arr1[i++];
        j++;
      }
    }
  while(i<l1)
    arr3[k++] = arr1[i++];
  while(j<l2)
    arr3[k++] = arr2[j++];

  return arr3;
}
void printArr(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
int main() {
  int A[SIZE] = {11, 34, 59, 65,78};
  int B[SIZE] = {10, 20, 31, 60, 75};
  int* C = merge(&A[0],&B[0],SIZE,SIZE);
  printArr(C,2*SIZE);
  return 0;
}
