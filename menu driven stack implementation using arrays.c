// Menu driven array implemented STACK operations
#include<stdio.h>
#include<stdlib.h>  

typedef struct Stack
{
  int top;
  int size;
  int* S;
}STACK;
void push(STACK* st)
{
  int num;
  printf("Enter the number to be pushed onto stack\n");
  scanf("%d",&num);
  if(st->top==st->size-1)
  {
    printf("Stack overflow\n");
    return;
  }
  st->top++;
  st->S[st->top] = num;
}
void isEmpty(STACK* st)
{
  if(st->top==st->size-1)
    printf("Stack Overflow\n");
  else if(st->top==-1)
    printf("Stack underflow\n");
  else
    printf("Stack is neither empty nor full\n");
  }
void display(STACK* st)
{
  int i;
  for(i=st->top;i>=0;i--)
    {
      printf("%d ",st->S[i]);
    }
}
int pop(STACK* st)
{
  int x=-1;
  if(st->top==-1)
  {
    printf("Stack underflow\n");
  }
  else
  {
    x = st->S[st->top--];
  }
  printf("The value deleted from the stack is %d",x);
  return x;
}
int main()
{
  int option;
  STACK s;
  s.size = 4;
  s.top = -1;
  s.S = (int*)malloc(s.size*sizeof(int));
  printf("\t\t\t####MENU####\n");
  do
    {
      printf("\n");
  printf("1.PUSH\n2.POP\n3.Underflow/overflow\n4.DISPLAY\n5.EXIT\n");
  printf("Enter option:\n");
  scanf("%d",&option);
  switch(option)
    {
      case 1:
        {
          push(&s);
          break;
        }
      case 2:
        {
          pop(&s);
          break;
        }
      case 3:
        {
          isEmpty(&s);
          break;
        }
      case 4:
        {
          display(&s);
          break;
        }
      case 5:
        {
          printf("Terminating Program..\n");
          exit(0);
        }
    }
      }while(option!=5);
  return 0;
}