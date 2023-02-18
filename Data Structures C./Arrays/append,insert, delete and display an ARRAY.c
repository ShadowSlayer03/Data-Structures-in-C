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
void append(ARR* arr,int val)
{
  arr->A[arr->length++] = val;
}
void insert(ARR* arr,int index)
{
  int i,val;
  if(index<0 || index>arr->length)
    return 0;

  printf("Enter the value to be inserted\n");
  scanf("%d",&val);
  for(i=arr->length;i>index;i--)
    {
      arr[i] = arr[i+1];
    }
  arr->A[i] = val;
}
void deleteElement(ARR* arr,int index)
  {
    int i;
    for(i=index;i<arr->length-1;i++)
      {
       arr->A[i] = arr->A[i+1];
      }
    arr->length--;
  }
int main()
{
  ARR array = {10,5,{1,2,3,4,5}};
   display(&array);
   // append(&array,24);
   // printf("\n");
   // display(&array);
  // insert(&array,2);
   printf("\n");
  // display(&array);
  deleteElement(&array,2);
  printf("\n");
  display(&array);
  return 0;
}
