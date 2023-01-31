// Taylor Series
// e^x = 1+x^2/2!+x^3/3!+x^4/4!........
#include<stdio.h>
#include<stdlib.h>

double e(int x,int n)
{
  static double p=1,f=1;
  double r;
  if(n==0)
    return 1;
  else
  {
    r = e(x,n-1);
    p = p*x;
    f = f*n;  
    return r+p/f;
  }
}
int main()
{
  double result = e(3,10);
  printf("%lf",result);
  return 0;
}