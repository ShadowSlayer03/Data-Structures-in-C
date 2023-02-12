// If there's a recursion such that the recursive call occurs more than one time in a function then it is called a Tree Recursion
// O(2^n) time complexity
#include<stdio.h>
#include<stdlib.h>

void func(int n)
{
  if(n>0)
  {
    printf("%d ",n);
    func(n-1);
    func(n-1);
  }
}
int main()
{
  func(3);
  return 0;
}
