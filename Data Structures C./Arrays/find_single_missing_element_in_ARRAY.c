// Find single missing element in a sorted array //
// 1st case(array elements starts from 1) - find sum of n elements by formula and then find sum of all nos. in array then subtract to find missing no.
// 2nd case(array element starts randomly) - find diff = starting element - index(0). Then see if for every element the same difference if not, then missing element = array index+diff 

#include<stdio.h>
#include<stdlib.h>
#define SIZE 9
int findMissing1(int* arr)
{
  int n = arr[SIZE-1];
  int totSum = (n*(n+1))/2;
  int i,sum=0;
  for(i=0;i<SIZE;i++)
    {
      sum = sum + arr[i];
    }
  return totSum - sum;
}
int findMissing2(int* arr)
{
  int diff = arr[0] - 0;
  int i;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]-i!=diff)
        break;
    }
  return i+diff;
}
int main()
{
  int A[SIZE] = {11,12,13,14,15,16,17,18,20};
  //int result = findMissing1(&A[0]);
  int result = findMissing2(&A[0]);
  printf("%d",result);
  return 0;
}
