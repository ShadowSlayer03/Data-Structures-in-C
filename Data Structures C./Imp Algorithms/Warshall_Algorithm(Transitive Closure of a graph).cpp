// Warshall Algorithm - find a matrix which shows if if every vertex is connected to every other vertex directly or indirectly.
// Also called Transitive Closure of a Graph.
// Time complexity O(n^3)
#include<iostream>
#include<vector>
using namespace std;

void check_edge_exists(vector<vector<int>> &matrix,int V)
{
  int i,j,k;
  for(k=0;k<V;k++)
  {
      for(i=0;i<V;i++)
      {
          for(j=0;j<V;j++)
          {
        matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
          }
      }
  }
}

int main()
{
  int V;
  cout<<"Enter the number of vertices:"<<endl;
  cin>>V;
  vector<vector<int>> matrix(V, vector<int>(V));
  int i,j;
  cout<<"Enter the adj matrix such that if edge exists directly input 1 else, input 0: "<<endl;
  for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
        {
          cin>>matrix[i][j];
        }
    }
  check_edge_exists(matrix,V);
  //Printing the answer matrix which replaced the adjacency matrix.
  cout<<"The required distance matrix is: "<<endl;
  for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
        {
          cout<<matrix[i][j]<<" ";
        }
      cout<<endl;
    }
  return 0;
}
