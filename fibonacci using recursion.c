// Fibonacci using Recursion
#include<stdio.h>
#include<stdlib.h>  

int fibonacci(int n)
{
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  else
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
  int n,fibo;
  printf("Enter the value of n\n");
  scanf("%d",&n);
  fibo = fibonacci(n);
  printf("The term %d in the fibonacci series is %d",n,fibo);
  return 0;
}