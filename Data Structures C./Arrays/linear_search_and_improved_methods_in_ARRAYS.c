#include<stdio.h>
#include<stdlib.h>
typedef struct array
{
  int size;
  int length;
  int A[10];
}ARR;

void display(ARR* arr)
{
  int i;
  for(i=0;i<arr->length;i++)
    {
      printf("%d ",arr->A[i]);
    }
}
void swap(int* a,int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
int LinearSearch(ARR* arr,int key)
{
  int i;
  for(i=0;i<arr->length;i++)
    {
      if(arr->A[i]==key)
        return i;
    }
  return -1;
}
int Transposition(ARR* arr,int key) // Method to improve Linear Search
{
  int i;
  for(i=0;i<arr->length;i++)
    {
      if(arr->A[i]==key)
      {
        swap(&arr->A[i],&arr->A[i-1]);
        return i;
      } 
    }
  return -1;
}
int MoveToHead(ARR* arr,int key)   // Method to improve Linear Search
{
  int i;
  for(i=0;i<arr->length;i++)
    {
      if(arr->A[i]==key)
      {
        swap(&arr->A[i],&arr->A[0]);
        return 0;
      } 
    }
  return -1;
}
int main()
{
  int x;
  ARR array = {10,5,{1,2,3,4,5}};
  display(&array);
  // x =LinearSearch(&array,2);
  // if(x==-1)
  //   printf("Search unsuccessful\n");
  // else
  //   printf("Search successful. The element is present at index %d",x);
  x = Transposition(&array,4);
  if(x==-1)
     printf("Search unsuccessful\n");
  else
     printf("Search successful. The element is present at index %d\n",x);

  // x = MoveToHead(&array,2);
  // if(x==-1)
  //    printf("Search unsuccessful\n");
  // else
  //    printf("Search successful. The element is present at index %d\n",x);
   display(&array);
  return 0;
}
