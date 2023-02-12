#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct node
{
int data;
struct node* next;
}NODE;
NODE* first = NULL;
int i;
void createLL(int* arr)
{
  NODE *temp,*p;
  first = (NODE*)malloc(sizeof(NODE));
  first->data = arr[0];
  first->next = NULL;
  temp = first;

  for(i=1;i<SIZE;i++)
    {
      p = (NODE*)malloc(sizeof(NODE));
      p->data = arr[i];
      p->next = NULL;
      temp->next = p;
      temp = p;
    }
}
void displayLL(NODE* p)
{
  if(p==NULL)
  {  printf("Linked list not present\n");
    exit(0); 
  }
  while(p!=NULL)
    {
      printf("%d ",p->data);
      p = p->next;
    }
}
NODE* search(int key, NODE* p,int* c)
{
  *c=0;
  while(p!=NULL)
    {
      if(key==p->data)
      {
        return p;
      }
      p = p->next;
      (*c)++;
    }
}
NODE* searchRec(int key, NODE* p)
{
  if(p==NULL)
    return NULL;
  else
  {
    if(key==p->data)
    return p;
    return searchRec(key,p->next);
  }
}
int main()
{
  int arr[SIZE] = {1,2,56,78,98};
  int count=0;
  createLL(&arr[0]);
  displayLL(first);
  NODE* seek = search(56,first,&count);
  printf("\n%d\n",seek->data);
  printf("%d",count+1); // at what position key is found in LL
  seek = searchRec(56,first);
  printf("\n%d\n",seek->data);
  return 0;
}
