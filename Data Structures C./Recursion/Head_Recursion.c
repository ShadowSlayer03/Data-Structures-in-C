// If there's a recursion such that the recursive call is the first line of code in the function then it is called a Head Recursion
#include<stdio.h>
#include<stdlib.h>

void func(int n)
{
  if(n>0)
  {
    func(n-1);
    printf("%d ",n);
  }
}
int main()
{
  func(6);
  return 0;
}
