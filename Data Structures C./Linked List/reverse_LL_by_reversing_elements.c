//Reversing a linked list
#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

typedef struct node
{
  int data;
  struct node* next;
}NODE;
NODE* first = NULL;
int i;

void reverseLL(NODE* p)
{
  int arr1[SIZE];
  i=0;
  while(p!=NULL)
    {
      arr1[i] = p->data;
      p=p->next;
      i++;
    }
  p = first;
  i=0;
  while(p!=NULL)
    {
      p->data = arr1[SIZE-i-1];
      p=p->next;
      i++;
    }
}
void reverseLLalt(NODE* p)
{
  int arr1[SIZE];
  i=0;
  while(p!=NULL)
    {
      arr1[i] = p->data;
      p=p->next;
      i++;
    }
  p = first;
  i=SIZE-1;
  while(p!=NULL)
    {
      p->data = arr1[i];
      p=p->next;
      i--;
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
  int arr[] = {1,2,3,3,5,5};
  createLL(&arr[0]);
  displayLL(first);
  reverseLL(first);
  printf("\n");
  displayLL(first);
  return 0;  
}
