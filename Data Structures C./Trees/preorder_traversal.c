// This is a half code that contains only the recursive and iterative way of traversing a tree in Preorder format 
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
  NODE** S;
}STACK;
int isEmpty(STACK* st)
{
  if(st->top==-1)
    return 1;
  else
    return 0;
}
void PreorderRec(NODE* p)
{
  printf("%d",p->data);
  PreorderRec(p->lchild);
  PreorderRec(p->rchild);
}

void PreorderIter(NODE* t)
{
  STACK* st;
  while(t!=NULL || !isEmpty(st))
    {
      if(t!=NULL)
      {
        printf("%d",t->data);
        push(st,&t);
        t = t->lchild;
      }
      else
      {
        t = pop(st);
        t = t->rchild;
      }
    }  
}
int main()
{
  return 0;
}
