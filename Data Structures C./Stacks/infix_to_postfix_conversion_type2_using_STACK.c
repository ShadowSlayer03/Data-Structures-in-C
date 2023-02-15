//Infix to Postfix Type 2
// Here both operands and operators are pushed into the stack
// Operands take highest priority
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stack
{
  int top;
  int size;
  char* S;
}STACK;
void push(STACK* st,char element)
{
  if(st->top==st->size-1)
  {
    printf("Stack overflow\n");
    return;
  }
  st->top++;
  st->S[st->top] = element;
}
char pop(STACK* st)
{
  char x;
  if(st->top==-1)
  {
    printf("Stack underflow\n");
    return 0;
  } 
  else
 {
    x = st->S[st->top--];
    return x;
 } 
}
int prec(char c)
{
  if(c=='+'||c=='-')
    return 1;
  else if(c=='/'||c=='*')
    return 2;
  else if(c==-1 || c=='(' || c==')')
    return 0;
  else
    return 3;
}
int isEmpty(STACK* st)
{
  if(st->top==-1)
    return 1;
  else
  return 0;
}
char stackTop(STACK* st)
{
  if(st->top==-1)
    return -1;
  else
  return st->S[st->top];
}
char* InfixtoPostfix(char* infix,STACK* st)
{
  char* postfix;
  postfix = (char*)malloc(strlen(infix)+1*sizeof(char));
  int i=0,j=0;
  while(infix[i]!='\0')
    {
      if(prec(infix[i])>prec(stackTop(st)) || infix[i]=='(')
      {
        push(st,infix[i]);
        i++;
      }
      else if(infix[i]==')')
      {
          while(st->S[st->top]!='(')
          {
              postfix[j++] = pop(st);
          }
          pop(st);
          i++;
      }
      else
      {
        postfix[j++] = pop(st);
      }
    }
  while(!isEmpty(st))
  {
    postfix[j++] = pop(st);
  }
  postfix[j] = '\0';
  return postfix;
}
int main()
{
  char* infix = "a+b*(c+f)/g";
  STACK* s;
  s = (STACK*)malloc(sizeof(STACK));
  s->top = -1;
  s->size = strlen(infix)+1; 
  s->S = (char*)malloc(s->size*sizeof(char));
  char* postfix = InfixtoPostfix(infix,s);
  printf("%s ",postfix);
  free(s);
  return 0;
}
