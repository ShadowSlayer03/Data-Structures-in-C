//creating and displaying linked lists
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};
struct Node* first=NULL;
createLL(int* arr) //Create linked list
{
  int i;
  struct Node *n,*temp;
  first = (struct Node*)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  temp = first;
  
  for(i=1;i<6;i++)
    {
      n = (struct Node*)malloc(sizeof(struct Node));
      n->data = arr[i];
      n->next = NULL;
      temp->next = n;
      temp = n;
    }
  
}
printLL(struct Node* p)  //display Linked List
{
  while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
}
int main()
{
  int arr[] = {1,2,3,4,5,6};
  int *ptr = &arr[0];
  createLL(ptr);
  printLL(first);
  return 0;
}
