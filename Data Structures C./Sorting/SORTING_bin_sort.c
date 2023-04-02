// Bucket/Bin Sort- Count table/ array of Node* pointers that point to Nodes.
// Every element in original array mapped to corresponding index in count table and a linked list is created at the same index in case an element repeats
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node
{
  int data;
  struct node* next;
}NODE;
int i;
int max(int* arr)
{
  int max=0;
  for(i=0;i<SIZE;i++)
    {
      if(arr[i]>max)
        max=arr[i];
    }
  return max;
}
void BinSort(int* arr)
{
  int Max = max(&arr[0]),j=0;
  NODE* p,*q;
  NODE** count = (NODE**)calloc(Max+1,sizeof(NODE*));

  for(i=0;i<SIZE;i++)
    {
      NODE* newnode = (NODE*)malloc(sizeof(NODE));
      newnode->data=arr[i];
      newnode->next=NULL;
      p=count[arr[i]];
      if(p==NULL)
      count[arr[i]] = newnode;
      else
      {
        while(p->next!=NULL)
          p=p->next;
        p->next = newnode;
      }
    }

  for(i=0;i<=Max;i++)
    {
      if(count[i]!=NULL)
      {
        p=count[i];
        while(p!=NULL)
          {
            arr[j++]=p->data;
            q=p;
            p=p->next;
            free(q);
          }
      }
    }
  free(count);
}
void printArr(int* arr)
{
  for(i=0;i<SIZE;i++)
    {
      printf("%d ",arr[i]);
    }
}
int main()
{
  int arr[SIZE]={1,67,45,69,3,67,90,54,78,67};
  BinSort(&arr[0]);
  printArr(&arr[0]);
  return 0;
}
