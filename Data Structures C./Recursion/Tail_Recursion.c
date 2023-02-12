// If there's a recursion such that the recursive call is the final line of code in the function then it is called a Tail Recursion
#include<stdio.h>
#include<stdlib.h>

void func(int n)
{
  if(n>0)
  {
    printf("%d ",n);
    func(n-1);
  }
}
int main()
{
  func(6);
  return 0;
}
