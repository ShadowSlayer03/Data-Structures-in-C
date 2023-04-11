// Merge Sort
// An array with 'n' elements is given. Each element is taken as an array and an array with 1 element is already sorted. Hence, in the first step we take 2 elements and sort them. Now we are left with 'n/2' arrays. 
// Then 2 of these arrays with 2 elements each are taken and merged and hence we get n/4 arrays. 
// This keeps continuing till all array elements are merged and hence all elements return sorted.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 12

void merge(int low,int high,int mid,int* arr)
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

void IterMergeSort(int* arr)
{
  int p,i,low,high,mid;
  for(p=2;p<=SIZE;p=p*2)
    {
      for(i=0;i+p-1<SIZE;i=i+p)
        {
          low = i;
          high = i+p-1;
          mid = (low+high)/2;
          merge(low,high,mid,arr);
        }
    }
    if(p/2<SIZE)
       merge(0,p/2-1,SIZE-1,arr);
}
void printArr(int* arr)
{
  int i;
  for(i=0;i<SIZE;i++)
    printf("%d ",arr[i]);
}
int main()
{
  int array[SIZE] = {34,45,23,14,6,2,9,4,78,18,90,73};
  IterMergeSort(array);
  printArr(&array[0]);
  return 0;
}
