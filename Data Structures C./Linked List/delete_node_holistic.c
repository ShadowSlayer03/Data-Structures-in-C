//Holistic delete
//Linked list nodes are starting from 1
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
int data = 65,i;

void createLL()
{
  NODE *temp,*p;
  first = (NODE*)malloc(sizeof(NODE));
  first->data = data;
  first->next = NULL;
  temp = first;
  data +=10;

  for(i=1;i<SIZE;i++)
    {
      p = (NODE*)malloc(sizeof(NODE));
      p->data = data;
      p->next = NULL;
      temp->next = p;
      temp = p;
      data+=10;
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
void deleteLL(NODE* p,int index)
{
  NODE* o=NULL;
  if(p==NULL)
  {
    printf("There's nothing to delete\n");
    exit(0);
  }
  if(index<1 || index>SIZE)
  {
    printf("Invalid index\n");
    exit(0);
  }
  else
  {
    if(index==1)
    {
      
      first = first->next;
      free(p);
    }
    else
    {
      for(i=1;i!=index;i++,p!=NULL)
        {
          o = p;
          p =  p->next;
        }
      o->next = p->next;
      free(p);
    }
  }
}
int main()
{
  createLL();
  displayLL(first);
  deleteLL(first,5);
  printf("\n");
  displayLL(first);
  return 0;
}
