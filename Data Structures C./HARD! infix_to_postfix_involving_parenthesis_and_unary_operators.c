// Infix to Postfix (expression involving parenthesis and unary operators)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct STACK
{
  int top;
  int size;
  char* S;
}STACK;
void push(STACK* st,int element)
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
    return -1;
  }
  else
  {
    x = st->S[st->top--];
    return x;
  }
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
int isOperand(char c)
{
  if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^'||c=='('||c==')')
    return 0;
  else
    return 1;
}
int precOut(char c)
{
  if(c=='+'||c=='-')     // Prec can be given as any no
    return 1;          // But L to R associativity-precOut<precIn 
  else if(c=='/'||c=='*')
    return 2;
  else if(c=='^')
    return 5;
  else if(c=='(')
    return 6;
  else if(c==')')
    return 0;
}
int precIn(char c)    // AND R to L associativity- precOut>precIn 
{
  if(c=='+'||c=='-')
    return 2;
  else if(c=='/'||c=='*')
    return 3;
  else if(c=='^')
    return 4;
  else if(c=='(')
    return 0;
  else if(c==-1)
    return -1;
}
char* InfixtoPostfix(char* infix,STACK* st)
{
  char* postfix;
  int i=0,j=0;
  postfix = (char*)malloc(strlen(infix)+1*sizeof(char));
  while(infix[i]!='\0')
    {
      if(isOperand(infix[i]))
      {
        postfix[j++] = infix[i++];
      }
      else
      {
        if(infix[i]==')'&&st->top==-1)
          {
            i++;
            continue;
          } 
        if(precOut(infix[i])>precIn(stackTop(st)))
        { 
          push(st,infix[i]);
          i++; 
        }
        else
        {
          if(infix[i]==')'&&stackTop(st)=='(')
            pop(st);
          else
          postfix[j++] = pop(st);
        }
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
  STACK* s;
  char* infix = "(a+b)*c-(d^e)^f-(g*r*r)";
  s = (STACK*)malloc(sizeof(STACK));
  s->top = -1;
  s->size = strlen(infix);
  s->S = (char*)malloc(sizeof(char));
  char* postfix = InfixtoPostfix(infix,s);
  printf("%s ",postfix);
  return 0;
}