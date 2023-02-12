//Check if linked list is sorted 
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
void checkSorted(NODE* p)
{
  while(p->next!=NULL)
    {
      
      if(p->data<p->next->data)
      {
        p = p->next;
      }
      else
      {
        printf("List is not sorted\n");
        exit(0);
      }
    }
  printf("Sorted\n");
}
int main()
{
  int arr[] = {1,2,3,5,4};
  createLL(&arr[0]);
  displayLL(first);
  checkSorted(first);
  return 0;
}
