// This is a half code that contains only the recursive and iterative way of traversing a tree in Inorder format 
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
void InorderRec(NODE* p)
{
  InorderRec(p->lchild);
  printf("%d",p->data);
  InorderRec(p->rchild);
}

void InorderIter(NODE* t)
{
  STACK* st;
  while(t!=NULL || !isEmpty(st))
    {
      if(t!=NULL)
      {
        push(st,&t);
        t = t->lchild;
      }
      else
      {
        t = pop(st);
        printf("%d",t->data);
        t = t->rchild;
      }
    }  
}
int main()
{
  return 0;
}
