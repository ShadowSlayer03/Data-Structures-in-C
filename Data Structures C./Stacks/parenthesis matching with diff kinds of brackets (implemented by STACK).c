// Parenthesis Matching - advanced
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
  int size;
  int top;
  char* S;
}STACK;
void push(STACK* st,char c)
{
  if(st->top==st->size-1)
  {
   printf("Stack overflow\n");
   return; 
  }  
  st->top++;
  st->S[st->top] = c;
}
int pop(STACK* st)
{
  int x=-1;
  if(st->top==-1)
     printf("Stack underflow\n");
  else
    x = st->S[st->top--];
  return x;
}
int isEmpty(STACK* st)
{
  if(st->top==-1)
    return 1;
  else
    return 0;
}
int isFull(STACK* st)
{
  if(st->top==st->size-1)
    return 1;
  else
    return 0;
}
int isBalanced(char* exp,STACK* st)
{
  int i;
  if(isFull(st))
  {
    printf("Full\n");
    exit(0);
  }
  for(i=0;exp[i]!='\0';i++)
  {
    if(exp[i]=='('||exp[i]=='['||exp[i]=='{') 
    {
      push(st,exp[i]);
    } 
    else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
    {
      if(st->top==-1)
        return 0;
      else
      {
        if(exp[i]==')' && st->S[st->top]=='(')
        pop(st);
        else if(exp[i]==']' && st->S[st->top]=='[')
        pop(st);
        else if(exp[i]=='}' && st->S[st->top]=='{')
        pop(st);
        else
        return 0;
      }
    }
  }
  return isEmpty(st)? 1:0;
}
int main()
{
  int size;
  char *exp = "{([a+q]/{9+23})-e}";
  STACK* stk;
  stk = (STACK*)malloc(sizeof(STACK));
  stk->size = strlen(exp);
  stk->top = -1;
  stk->S = (char*)malloc(size*sizeof(char));
  int result = isBalanced(exp,stk);
  if(result) printf("Parenthesis Matched\n");
  else printf("Parenthesis Not Matched\n");
  return 0;
}
