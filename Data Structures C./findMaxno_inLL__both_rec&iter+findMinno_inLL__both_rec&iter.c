#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 6

int i;
typedef struct node
{
  int data;;
  struct node* next;          
}NODE;
NODE* first = NULL;
void createLL(int *array)
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
int findMax(NODE* p)  //iterative 
{
  int max = INT_MIN;
  if(p==0)
  {
    printf("Linked List not present\n");
    exit(0);
  }
  while(p!=NULL)
    {
      if(p->data>max)
      {
        max = p->data; 
      }
      p = p->next;
    }
  return max;
}
int findMaxRec(NODE* p)      //recursive
{
  int max = INT_MIN,x;
  if(p!=0)
  {
    x = findMaxRec(p->next);
    if(x>p->data)
      return x;
    else 
      return p->data;
  }
  else  //p==0
    return max;
}
int findMin(NODE* p)  //iterative 
{
  int min = INT_MAX;
  if(p==0)
  {
    printf("Linked List not present\n");
    exit(0);
  }
  while(p!=NULL)
    {
      if(p->data<min)
      {
        min = p->data; 
      }
      p = p->next;
    }
  return min;
}
int findMinRec(NODE* p)      //recursive
{
  int min = INT_MAX,x;
  if(p!=0)
  {
    x = findMinRec(p->next);
    if(x<p->data)
      return x;
    else 
      return p->data;
  }
  else  //p==0
    return min;
}
int main()
{
  int arr[SIZE];
  for(i=0;i<SIZE;i++)
    {
      scanf("%d",&arr[i]);
    }
  createLL(&arr[0]);
  displayLL(first);
  printf("\n%d\n",findMax(first));
  printf("%d\n",findMaxRec(first));
  printf("%d\n",findMinRec(first));
  printf("%d\n",findMin(first));
  return 0;
}