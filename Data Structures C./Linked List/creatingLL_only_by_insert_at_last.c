//Creating a linked list by repeated adding at the last
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
NODE* last = NULL;
void insertLast(int val,NODE* p)
{
  NODE* newnode;
  newnode = (NODE*)malloc(sizeof(NODE));
  
  newnode->data = val;
  newnode->next = NULL;
  if(p==NULL)
  {
    first = newnode;
    last = newnode;
  }
  else
  {
    last->next = newnode;
    last = newnode;
  }
}
void displayLL(NODE* p)
{
  while(p!=0)
    {
      printf("%d ",p->data);
      p = p->next;
    }
}
int main()
{
  
  insertLast(23,first);
  insertLast(34,first);
  insertLast(45,first);
  displayLL(first);
  return 0;
}
