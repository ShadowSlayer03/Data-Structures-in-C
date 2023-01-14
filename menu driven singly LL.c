// Menu driven singly linked list operations
#include<stdio.h>
#include<stdlib.h>  

typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
void displayLL(NODE* p)
{
  while(p!=NULL)
    {
      printf("%d ",p->data);
      p = p->next;
    }
}
void insertStart(NODE* p)
{
  int element;
  printf("Enter the element\n");
  scanf("%d",&element);
  NODE* newnode =(NODE*)malloc(sizeof(NODE));
  newnode->data = element;
  newnode->next = first;
  first = newnode;
  displayLL(first);
}
void insertAtNode(NODE* p)
{
  int element,existNum;
  printf("Enter the existing element\n");
  scanf("%d",&existNum);
  printf("Enter the element\n");
  scanf("%d",&element);
  NODE* newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = element;
  if(p==0)
  {
    printf("No nodes present\n");
    return;
  }
  while(p->data!=existNum)
    {
      p = p->next;
    }
  if(p->next==NULL)
  {
    p->next = newnode;
    newnode->next = NULL;
  }
  else
  {
    newnode->next = p->next;
    p->next = newnode;
  }
  displayLL(first);
}
void deleteNode(NODE* p)
{
  int existNum,x;
  NODE* o =NULL;
  printf("Enter the existing element\n");
  scanf("%d",&existNum);
  while(p!=NULL)
    {
      if(p->data==existNum)
      {
        if(p==first)
        {
          first = p->next;
          free(p);
        }
        else
        {
          o->next = p->next;
          x = p->data;
          free(p);
        }
        displayLL(first);
        return;
      }
      o = p;
      p=p->next;
    }
  printf("Element %d not found!",existNum);
  displayLL(first);
}
void searchLL(NODE* p)
{
  int key;
  printf("Enter a search key\n");
  scanf("%d",&key);
  while(p!=NULL)
    {
      if(p->data==key)
      {
        printf("The element is present\n");
        return;
      }
      p = p->next;
    }
  printf("Element is not present in Linked List\n");
  return;
}
int main()
{
  int option;
  printf("\t\t\t####MENU####\n");
  do
    {
      printf("\n");
  printf("1.Insert at start\n2.Insert after given data\n3.Delete node with given data\n4.Search for a given value\n5.Display list\n6.Exit\n");
  printf("Enter option:\n");
  scanf("%d",&option);
  switch(option)
    {
      case 1:
        {
          insertStart(first);
          break;
        }
      case 2:
        {
          insertAtNode(first);
          break;
        }
      case 3:
        {
          deleteNode(first);
          break;
        }
      case 4:
        {
          searchLL(first);
          break;
        }
      case 5:
        {
          displayLL(first);
          break;
        }
      case 6:
        {
          printf("Program terminating...\n");
          exit(0);
        }
    }
      }while(option!=6);
  return 0;
}