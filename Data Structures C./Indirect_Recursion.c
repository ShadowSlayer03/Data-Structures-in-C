// If there's a function A and it calls another function B which again calls function A during its execution, then this is indirect recursion
#include<stdio.h>
#include<stdlib.h>
void funcA(int n);
void funcB(int n);
void funcA(int n)
{
  if(n>0)
  {
    printf("%d ",n);
    funcB(n-1);
  }
}
void funcB(int n)
{
  if(n>0)
  {
    printf("%d ",n);
    funcA(n/2);
  }
}
int main()
{
  funcA(20);
  return 0;
}