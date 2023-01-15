//Stack
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
  int size;
  int top;
  int* S;
}STACK;

STACK* createStack()
{
  STACK* st;
  st = (STACK*)malloc(sizeof(STACK));
  printf("Enter the size of the stack\n");
  scanf("%d",&st->size);
  st->top = -1;
  st->S = (int*)malloc(sizeof(int)*st->size);
  return st;
}
void displayStack(STACK* st)
{
  int i;
  if(st->top==-1)
  {
    printf("There are no elements in stack to display\n");
    exit(0);
  }
  for(i=st->top;i>=0;i--)
    {
      printf("%d ",st->S[i]);
    }
  printf("\n");
}
void push(STACK* st,int x)
{
  if(st->top==st->size-1)
  {
    printf("Stack overflow\n");
    exit(0);
  }
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}
int pop(STACK* st)
{
  int x=-1;
  if(st->top==-1)
    printf("Stack underflow\n");
  else
  {
    x = st->S[st->top--];  //Taken the value that was popped into x and decremented top
  }
  return x;
}
int isEmpty(STACK* st)
{
  if(st->top==-1)
  {
    return 1;
  }
  return 0;
}
int isFull(STACK* st)
{
  if(st->top==st->size-1)
  {
    return 1;
  }
  return 0;
}
int peek(STACK* st,int index)
{
  int x=-1;
  if(st->top+1<0)
    printf("Invalid Index\n");
  else
    x = st->S[st->top-index+1];
  return x;
}
int stackTop(STACK* st)
{
  int x=-1;
  if(!isEmpty(st))
    return st->S[st->top];
  return x;
}
int main()
{
  STACK *stack;
  int a,b;
  stack = createStack();
  push(stack,45);
  push(stack,67);
  push(stack,89);
  displayStack(stack);
  b = isFull(stack);
  if(b) printf("The stack is full\n");
  else printf("The stack is not full\n");
  a = isEmpty(stack);
  if(a) printf("The stack is empty\n");
  else printf("The stack is not empty\n");
  displayStack(stack);
  int result = stackTop(stack);
  printf("%d\n",result);
  result = peek(stack,2);
  printf("%d\n",result);
  return 0;
}