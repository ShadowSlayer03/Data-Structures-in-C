//Queue using linked lists
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node* next;
}NODE;
NODE* front = NULL;
NODE* rear = NULL;
void enqueue(int x) // Queue is full when heap is full ie.newnode==NULL       
{
  NODE* newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = x;
  newnode->next = NULL;
  if(newnode==NULL)
  {
    printf("Queue is full\n");
  }
  else
  {
    if(front==NULL)  // If there's only one node in LL
      front=rear=newnode;
    
    rear->next = newnode;
    rear = newnode;
  }
}
int dequeue()
{
  int x=-1;
  NODE* temp;
  if(front==rear && rear==NULL)
  {
    printf("There's nothing in the queue\n");
  }
  else
  {
    x = front->data;
    temp = front;
    front = front->next;
    free(temp);
  }
  return x;
}
void display(NODE* p)
{
  while(p!=rear)
    {
      printf("%d ",p->data);
      p=p->next;
    }
}
int main()
{
  enqueue(34);
  enqueue(45);
  enqueue(56);
  enqueue(67);
  enqueue(78);
  display(front);
  printf("\n");
  dequeue();
  dequeue();
  display(front);
  printf("\n");
  return 0;
}
