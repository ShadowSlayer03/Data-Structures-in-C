// Evaluation of an infix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
   int top;
   int size;
   char* S;
}STACK;
typedef struct stack1
{
   int top;
   int size;
   int* S;
}ST;
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
  if(c=='/'||c=='*'||c=='+'||c=='-')
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
        if(prec(infix[i])>prec(st->S[st->top]))
        {  
          push(st,infix[i]);
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
void push1(ST* st,int i)
{
  if(st->top==st->size-1)
  {
    printf("Stack overflow\n");
    return;
  }
  st->top++;
  st->S[st->top] = i;
}
int pop1(ST* st)
{
  int x;
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
int evalPostfix(char* postfix)
{
  int i,x1,x2,res;
  ST s;
  s.top = -1;
  s.size = strlen(postfix)+1;
  s.S = (int*)malloc(sizeof(int)*s.size);
  for(i=0;postfix[i]!='\0';i++)
    {
      if(isOperand(postfix[i]))
      {
        push1(&s,postfix[i]-'0');
      }
      else
      {
        x1 = pop1(&s);
        x2 = pop1(&s);
        switch(postfix[i])
          {
            case '+':
              {
                res = x2+x1;
                push1(&s,res);
                break;
              }
            case '-':
              {
                res = x2-x1;
                push1(&s,res);
                break;
              }
            case '/':
              {
                res = x2/x1;
                push1(&s,res);
                break;
              }
            case '*':
              {
                res = x2*x1;
                push1(&s,res);
                break;
              }
          }
      }
    }
  return pop1(&s);
}
int main()
{
  STACK* stk;
  stk = (STACK*)malloc(sizeof(STACK));
  char* infix = "3+8-2*7*4/2-1";
  stk->top = -1;
  stk->size = strlen(infix);
  stk->S = (char*)malloc(stk->size*sizeof(char));
  char* postfix = InfixtoPostfix(infix,stk);
  printf("%s \n",postfix);
  int result = evalPostfix(postfix);
  printf("%d",result);
  free(stk);
  return 0;
}