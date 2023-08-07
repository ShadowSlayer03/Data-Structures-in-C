#include<iostream>
#include<vector>
using namespace std;

int binoCoeff(int n, int r,vector<vector<int>> &dp)
{
  if(r==0 || n==r)
  return 1;

  if(dp[n][r]!=-1)
    return dp[n][r];

  dp[n][r] = binoCoeff(n-1,r-1,dp)+binoCoeff(n-1,r,dp);
  return dp[n][r];
}
int main()
{
  int n,r;
  cout<<"Enter the n and r value"<<endl;
  cin>>n>>r;
  vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
  //Above vector with n+1 rows and r+1 cols, all values initialised to -1
  cout<<"The required binomial coefficient is "<<binoCoeff(n,r,dp)<<endl;
  return 0;
}
