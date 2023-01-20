//Holistic Insert fn that inserts node at any position
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
int value = 10,i;
void createLL(int size)
{
  NODE *temp,*p;
  first = (NODE*)malloc(sizeof(NODE));
  first->data = value;
  first->next = NULL;
  temp = first;
  value = value + 11;
  
  for(i=1;i<size;i++)
    {
      p = (NODE*)malloc(sizeof(NODE));
      p->data = value;
      p->next = NULL;
      temp->next = p;
      temp = p;  
      value = value+11;
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
void Insert(NODE* p,int size)
{
  NODE* newnode=(NODE*)malloc(sizeof(NODE));
  int element,index; //index 0 is b4 the first node,index 1 is b/w 1st and 2nd node
  printf("Enter the element to be inserted in LL and index of where to be inserted\n");
  scanf("%d",&element);
  scanf("%d",&index);
  if(index<0 || index>(size-1))
  {
    printf("Unaccessible index\n");
    exit(0);
  }
  if(index==0)
  {
    newnode->data = element;
    newnode->next = first;
    first = newnode;
  }
  else
  {
    for(i=0;i<(index-1);i++)
      {
        p = p->next;
      }
    newnode->data = element;
    newnode->next = p->next;
    p->next = newnode;
  }
  
}
int main()
{
  int size;
  printf("Enter the size of the Linked List\n");
  scanf("%d",&size);  
  createLL(size);
  displayLL(first);
  printf("\n");
  Insert(first,size);
  displayLL(first);
  return 0;
}