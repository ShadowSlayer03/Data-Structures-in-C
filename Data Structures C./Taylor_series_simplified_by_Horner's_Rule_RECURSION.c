// Taylor Series using Horner's Rule
// e^x = 1+x^2/2!+x^3/3!+x^4/4!........
#include<stdio.h>
#include<stdlib.h>

double eRec(int x,int n)  // Recursive
{
  static double s;
  if(n==0)
    return s;
  else
  {
    s = 1+x*s/n;
    return eRec(x,n-1);
  }
}
double e(int x,int n)    // Iterative
{
  int i;
  double s=1,num=1,den=1;
  for(i=1;i<=n;i++)
    {
      num = num*x;
      den = den*i;
      s+= num/den;
    }
  return s;
}
int main()
{
  double result = eRec(2,10);
  printf("%lf\n",result);
  result = e(2,10);
  printf("%lf\n",result);
  return 0;
}