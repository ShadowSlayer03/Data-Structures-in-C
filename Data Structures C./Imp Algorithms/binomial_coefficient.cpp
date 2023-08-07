#include<iostream>
using namespace std;

int binoCoeff(int n, int r)
{
  if(r==0 || n==r)
    return 1;
  else
    return binoCoeff(n-1,r-1)+binoCoeff(n-1,r);
}
int main()
{
  int n,r;
  cout<<"Enter the n and r value"<<endl;
  cin>>n>>r;
  cout<<"The required binomial coefficient is "<<binoCoeff(n,r)<<endl;
  return 0;
}
