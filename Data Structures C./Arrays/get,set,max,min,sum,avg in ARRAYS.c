#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int get(int* arr,int index)
{
  return arr[index];
}
void set(int* arr,int index,int x)
{
  arr[index] = x;
}
int max(int* arr)
{
  int max=arr[0],i;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]>max)
        max = arr[i];
    }
  return max;
}
int min(int* arr)
{
  int min=arr[0],i;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]<min)
        min = arr[i];
    }
  return min;
}
int sum(int* arr)
{
  int i,sum=0;
  for(i=0;i<SIZE;i++)
    {
      sum = sum+arr[i];
    }
  return sum;
}
int sumRec(int* arr,int n)
{
  if(n<=0)
    return 0;
  else
    return sumRec(arr,n-1)+arr[n-1];
}
float average(int* arr,int n)
{
  int sum=0,i;
  for(i=0;i<SIZE;i++)
    {
      sum = sum+arr[i];
    }
  return (float)sum/n;
}
int main()
{
  int A[SIZE]={12,23,34,45,56,67,78,89,90,101};
  // printf("%d\n",sumRec(&A[0],SIZE));
  // printf("%d\n",sum(&A[0]));
  // printf("%.2f\n",average(&A[0],SIZE));
  printf("%d\n",max(&A[0]));
  printf("%d\n",min(&A[0]));
  printf("%d\n",get(&A[0],2));
  set(&A[0],4,234);
  printf("%d\n",get(&A[0],4));
  return 0;
}
