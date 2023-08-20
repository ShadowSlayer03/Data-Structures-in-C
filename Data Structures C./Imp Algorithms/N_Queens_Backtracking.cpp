// N-Queens problem using BackTracking 
// Queens should be placed in a NXN board so that no 2 Queens are placed in the same row, column or cross diagonally.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row, int col, vector<string>& board,int N)
{
  int rowSave = row;
  int colSave = col;
  // Checking top-left diagonal
  while(row>=0 && col>=0)
    {
      if(board[row][col]=='Q')
        return false;
      row--;
      col--;
    }

  row = rowSave;
  col = colSave;
  // Checking row in left-straight direction
  while(col>=0)
    {
      if(board[row][col]=='Q')
        return false;
      col--;
    }

  row = rowSave;
  col = colSave;
  // Checking bottom-left diagonal
  while(row<N && col>=0)
    {
      if(board[row][col]=='Q')
        return false;
      row++;
      col--;
    }
  return true;
}
void NQueens(int col, vector<string>& board,vector<vector<string>>& ans, int  N)
{
  int row;
  if(col==N)
  {
    ans.push_back(board);
    return;
  }
  for(row=0;row<N;row++)
    {
      if(isSafe(row,col,board,N))
      {
        board[row][col] = 'Q';
        NQueens(col+1,board,ans,N);
        board[row][col] = '.';
      }
    }
}
int main()
{
  int n,i,j;
  cout<<"Enter N(the size of the chessboard): "<<endl;
  cin>>n;
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n,'.');
  for(i=0;i<n;i++)
    board[i] = s;
  NQueens(0,board,ans,n);

  for(i=0;i<ans.size();i++)
    {
      cout<<"Arrangement "<<i+1<<":"<<endl;
      for(j=0;j<ans[i].size();j++)
        {
          cout<<ans[i][j];
          cout<<endl;
        }
      cout<<endl;
    }
  return 0;
}
