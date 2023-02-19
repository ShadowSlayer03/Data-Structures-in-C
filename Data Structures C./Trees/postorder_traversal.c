// This is a half code that contains only the recursive and iterative way of traversing a tree in Postorder format 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  struct node* lchild;
  int data;
  struct node* rchild;
}NODE;
typedef struct stack
{
  int top;
  int size;
  int* S;
}STACK;
int isEmpty(STACK* st)
{
  if(st->top==-1)
    return 1;
  else
    return 0;
}
void PostorderRec(NODE* p)
{
  PostorderRec(p->lchild);
  PostorderRec(p->rchild);
  printf("%d",p->data);
}

void PostorderIter(NODE* t)
{
  STACK* st;
  long int temp;
  while(t!=NULL || !isEmpty(st))
    {
      if(t!=NULL)
      {
        push(st,&t);
        t = t->lchild;
      }
      else
      {
        temp = pop(st);
        if(temp>0)
        {
          push(&st,-temp);
          t = ((NODE*)temp)->rchild;
        }
        else
        {
          printf("%d",((NODE*)temp)->data);
          t = NULL;
        }
      }
    }  
}
int main()
{
  return 0;
}
