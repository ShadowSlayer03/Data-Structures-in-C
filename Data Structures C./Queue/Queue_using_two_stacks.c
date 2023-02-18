//Queue using 2 stacks
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int top;
  int size;
  int* S;
}STACK;
STACK* create()
{
  STACK* st;
  st = (STACK*)malloc(sizeof(STACK));
  st->top = -1;
  st->size = 10;
  st->S = (int*)malloc(sizeof(int)*st->size);
  return st;
}
void push(STACK* st,int x)
{
  if(st->top==st->size-1)
  {
    printf("Stack overflow\n");
    return;
  }
  st->top++;
  st->S[st->top] = x;
}
int pop(STACK* st)
{
  int x=0;
  if(st->top==-1)
  {
    printf("Stack underflow\n");
  }
  else
  {
    x = st->S[st->top--];
  }
  return x;
}
int isFull(STACK* st1)
{
  if(st1->top==st1->size-1)
    return 1;
  else 
    return 0;
}
void enqueue(STACK* st1)
{
  int x;
  if(isFull(st1))
  {
    printf("Stack full\n");
    return;
  }
  printf("Enter the element to be pushed\n");
  scanf("%d",&x);
  push(st1,x);
}
void dequeue(STACK* st1,STACK* st2)
{
  int x;
  if(st2->top==-1) // Making sure that stack 2 is empty
  {
   while(st1->top!=-1)  // Till stack 1 is empty push elements to stack 2
    {
      x = pop(st1);
      push(st2,x);
    } 
  }
  x =pop(st2);
  printf("%d was popped\n",x);
}
void display(STACK* st)
{
  int i;
  for(i=st->top;i>-1;i--)
    {
      printf("%d ",st->S[i]);
    }
}
int main()
{
  STACK *stack1,*stack2;
  stack1 = create();
  stack2 = create();
  enqueue(stack1);
  enqueue(stack1);
  enqueue(stack1);
  enqueue(stack1);
  dequeue(stack1,stack2);
  display(stack2);
  return 0;
}
