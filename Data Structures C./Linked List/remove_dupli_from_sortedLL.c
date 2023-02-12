//Remove duplicates from a sorted linked list 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 9

typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
int i;
void removeDupli(NODE* p)
{
  NODE* q=p->next;
  while(q!=NULL)
    {
      if(p->data==q->data)
      {
        p->next = q->next;
        free(q);
        q = p->next;
      }
      else
      {
        p = q;
        q = q->next;
      }
    }
}
void createLL(int* array)
{
  NODE *temp,*p;
  first = (NODE*)malloc(sizeof(NODE));
  first->data = array[0];
  first->next = NULL;
  temp = first;

  for(i=1;i<SIZE;i++)
    {
      p = (NODE*)malloc(sizeof(NODE));
      p->data = array[i];
      p->next = NULL;
      temp->next = p;
      temp = p;
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

int main()
{
  int arr[] = {1,2,3,3,5,6,7,8,8};
  createLL(&arr[0]);
  displayLL(first);
  removeDupli(first);
  printf("\n");
  displayLL(first);
  return 0;  
}
