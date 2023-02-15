// Infix to Postfix Conversion TYPE 1
// Operands are taken directly to postfix and operators are taken in stack and then to postfix acc to their precedence
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
   int top;
   int size;
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
  char x;
  if(st->top==-1)
  {
    printf("Stack underflow\n");
    return -1;
  }
  else{
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
int prec(char c)
{
  if(c=='/'||c=='*')
    return 2;
  else if(c=='-'||c=='+')
    return 1;
  else
  return 0;  // case where stack is empty 
}
int isOperand(char c)
{
  if(c=='/'||c=='*'||c=='+'||c=='-'||c=='('||c==')')
    return 0;
  else
    return 1;
}
char* InfixtoPostfix(char* infix,STACK* st)
{
  char* postfix;
  postfix = (char*)malloc(strlen(infix)+1 * sizeof(char));
  int i=0,j=0;
  while(infix[i]!='\0')
  {
      if(isOperand(infix[i]))
        postfix[j++] = infix[i++];
        
      else
      {
        if((prec(infix[i])>prec(st->S[st->top])) || infix[i]=='(')
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
          postfix[j++]= pop(st);
        }   
      }
  }
  while(!isEmpty(st))
    {
      postfix[j++]= pop(st);
    }
  postfix[j]='\0';
  return postfix;
}
int main()
{
  STACK* stk;
  stk = (STACK*)malloc(sizeof(STACK));
  char* infix = "b*(c-d)+e/g";
  stk->top = -1;
  stk->size = strlen(infix);
  stk->S = (char*)malloc(stk->size*sizeof(char));
  char* result = InfixtoPostfix(infix,stk);
  printf("%s ",result);
  free(stk);
  return 0;
}
