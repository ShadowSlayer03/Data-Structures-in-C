//Code insert in sorted linked list
#include<stdio.h>
#include<stdlib.h>
int i;
typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
void insert(int val)
{
  NODE *p,*q,*newnode;
  p = first;
  q = NULL;
  newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = val;
  newnode->next = NULL;
  if(first==NULL)
  {
    first = newnode;
  }
  else{
    while(p!=NULL && p->data<val)
    {
      q = p;
      p = p->next;
    }
  if(p == first && q == NULL)
  {
    newnode->next = first;
    first = newnode;
    return; 
  }
  newnode->next = q->next;
  q->next = newnode;
}
}
void displayLL(NODE* p)
{
  while(p!=NULL)
    {
      printf("%d ",p->data);
      p = p->next;
    }
}
void createLL(int* array)
{
  NODE *temp,*q;
  first = (NODE*)malloc(sizeof(NODE));
  first->data = array[0];
  first->next = NULL;
  temp = first;

  for(i=1;i<5;i++)
    {
      q = (NODE*)malloc(sizeof(NODE));
      q->data = array[i];
      q->next = NULL;
      temp->next = q;
      temp = q;
    }
}
int main()
{
  // int arr[] = {12,23,34,45,67};
  // createLL(&arr[0]);
  insert(27);
  insert(45);
  insert(33);

  displayLL(first);
  return 0;
} 
//
