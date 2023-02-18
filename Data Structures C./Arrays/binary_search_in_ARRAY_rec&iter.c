#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int BinarySearch(int* arr,int size)
{
  int low,high,mid,key;
  low = 0;
  high = size-1;
  printf("Enter the key\n");
  scanf("%d",&key);
  while(low<=high)
    {
      mid = (low+high)/2;
      if(key>arr[mid])
      {
        low = mid+1;
      }
      else if(key<arr[mid])
      {
        high = mid-1;
      }
      else
        return mid;
    }
  return -1;
}
int BinarySearchRec(int* arr,int size,int low,int high, int key)
{ 
  int mid;
  if(low<=high)
  {
    mid = (low+high)/2;
    if(key>arr[mid])
    {
      return BinarySearchRec(arr,size,mid+1,high,key);
    }
    else if(key<arr[mid])
    {
      return BinarySearchRec(arr,size,low,mid-1,key);
    }
    else 
      return mid;
  }
  return -1;
}
int main()
{
  int arr[10],i,x,size;
  printf("Enter the elements of the sorted array\n");
  for(i=0;i<10;i++)
    {
      scanf("%d",&arr[i]);
    }
  // x = BinarySearch(&arr[0],SIZE);
  // if(x>0)
  // {
  //   printf("The key is found at index %d",x);
  // }
  // else
  //   printf("The key is not found");
  
  x = BinarySearchRec(arr,SIZE,0,SIZE-1,6);
  if(x>0)
  {
    printf("The key is found at index %d",x);
  }
  else
    printf("The key is not found");
      
  return 0;
}
