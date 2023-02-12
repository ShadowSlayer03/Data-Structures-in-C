//Stack using singly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* top = NULL;
void createStack(int* arr,int size)
{
  int i;
  NODE *temp,*p;
  top = (NODE*)malloc(sizeof(NODE));
  top->data = arr[size-1];
  top->next = NULL;
  temp = top;
  for(i=size-2;i>=0;i--)
    {
     p = (NODE*)malloc(sizeof(NODE));
     p->data = arr[i];
     p->next = NULL;
     temp->next = p;
     temp = p; 
    }
}
void displayStack(NODE* p)
{
  while(p!=NULL)
    {
      printf("%d ",p->data);
      p = p->next;
    }
  printf("\n");
}
int pop(NODE* p)    // index is the place to be popped
{
  int x = -1,i;
  NODE* q;
  if(p==NULL)
    printf("Stack underflow\n");
  else
  {
    q = p->next;
    x = p->data;
    free(p);
    top = q;
  }
  return x;
}
void push()
{
  int element;
  printf("Enter the element to be inserted\n");
  scanf("%d",&element);
  NODE* newnode = (NODE*)malloc(sizeof(NODE));
  if(newnode==0)
  {
    printf("Stack overflow\n");
    return;
  }
  newnode->data = element;
  newnode->next = top;
  top = newnode;
}
int isEmpty(NODE* p)
{
  if(p==NULL)
    return 1;
  else 
    return 0;
}
int isFull(NODE* p)
{
  NODE* newnode = (NODE*)malloc(sizeof(NODE));
  if(!newnode)
    return 1;
  else
    return 0;
}
int stackTop(NODE* p)
{
  if(!p)
    return -1;
  else
    return top->data;
}
int peek(NODE* p,int index)
{
  int i;
  if(p==NULL)
  {  printf("Nothing to peek\n");
    return -1; }
  for(i=0;p!=NULL && i<index-1;i++)
    {
      p = p->next;
    }
  return p->data;
}
int main()
{
  int size,i;
  int* dArr;
  printf("Enter the size of the stack:\n");
  scanf("%d",&size);
  dArr = (int*)malloc(sizeof(int)*size);
  printf("Enter the elements of the array\n");
  for(i=0;i<size;i++)
    {
      scanf("%d",&dArr[i]);
    }
  createStack(dArr,size);
  displayStack(top);
  push();
  displayStack(top);
  // pop(top);
  // displayStack(top);
  int result = isEmpty(top);
  if(result) printf("Stack is empty\n");
  else printf("Stack is not empty\n");
  result = isFull(top);
  if(result) printf("Stack is full\n");
  else printf("Stack is not full\n");
  printf("%d\n",stackTop(top));
  result = peek(top,3);
  printf("%d ",result);
  return 0;
}
