// Merge Sort
// An array with 'n' elements is given. Each element is taken as an array and an array with 1 element is already sorted. Hence, in the first step we take 2 elements and sort them. Now we are left with 'n/2' arrays. 
// Then 2 of these arrays with 2 elements each are taken and merged and hence we get n/4 arrays. 
// This keeps continuing till all array elements are merged and hence all elements return sorted.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

void merge(int low,int mid,int high,int* arr)
{
  int i,j,k;
  i = low;
  j = mid+1;
  k=low;
  int* Arr = (int*)malloc(2*SIZE*sizeof(int));
  while(i<mid+1 && j<high+1)
    {
      if(arr[i]<arr[j])
        Arr[k++] = arr[i++];
      else if(arr[i]>arr[j])
        Arr[k++] = arr[j++];
      else
      {
        Arr[k++] = arr[i++];
        j++;
      }
    }
  while(i<mid+1)
    Arr[k++] = arr[i++];
  while(j<high+1)
    Arr[k++] = arr[j++];
  
  for(i=low;i<=high;i++)
    arr[i] = Arr[i];
  
}

void RecMergeSort(int* arr, int low, int high)
{
  int mid;
  if(low<high)
  {
    mid = (low+high)/2;
    RecMergeSort(arr,low,mid);
    RecMergeSort(arr,mid+1,high);
    merge(low,mid,high,arr);
  }
}
void printArr(int* arr)
{
  int i;
  for(i=0;i<SIZE;i++)
    printf("%d ",arr[i]);
}
int main()
{
  int array[SIZE] = {34,45,23,14,6,2,9,4,78,56,1};
  RecMergeSort(array,0,SIZE-1);
  printArr(&array[0]);
  return 0;
}
