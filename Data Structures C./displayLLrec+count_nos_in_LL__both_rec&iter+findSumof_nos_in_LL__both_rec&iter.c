#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
  int data;
  struct Node* next;
}NODE;

NODE* first=NULL;
int i;

void createLL(int* arr)  //create the linked list
{
  NODE *temp,*p;
  first = (NODE*)malloc(sizeof(NODE));
  first->data = arr[0];
  first->next = NULL;
  temp = first;

  for(i=1;i<5;i++)
    {
      p = (NODE*)malloc(sizeof(NODE));
      p->data = arr[i];
      p->next = NULL;
      temp->next = p;
      temp = p;
    }
}
void display(NODE* n)  //display contents of linked list
{
  while(n!=0)
    {
      printf("%d ",n->data);
      n = n->next;
    }
}
void displayLLRec(NODE* n)    //display contents of linked list recursively
{
  if(n!=NULL)
    {
      printf("%d ",n->data);
      return displayLLRec(n->next);
    }
}
int count(NODE* p)  // counts the number of values in linked list
{
  int count =0;
  while(p!=0)
    {
      count++;
      p = p->next;
    }
  return count;
}
int Rcount(NODE* p)   // counts the number of values in linked list recursively
{
  if(p!=NULL)
  {
    return Rcount(p->next)+1;
  }
  else
    return 0;
}
int findSum(NODE* p)   // finds the sum of values in linked list 
{
  int sum =0;
  while(p!=NULL)
    {
      sum = sum+p->data;
      p = p->next;
    }
  return sum;
}
int findSumRec(NODE* p)    // finds the sum of values in linked list recursively
{
  if(p!=0)
  {
    return findSumRec(p->next)+p->data;
  }
  else
  {
    return 0;
  }
}
int main()
{
  int arr[5];
  printf("Enter the elements of the array\n");
  for(i=0;i<5;i++)
    {
      scanf("%d",&arr[i]);
    }
  createLL(&arr[0]);
  displayLLRec(first);
  display(first);
  printf("\n%d",count(first));
  printf("\n%d",Rcount(first));
  printf("\n%d",findSum(first));
  printf("\n%d",findSumRec(first));
  return 0;
}