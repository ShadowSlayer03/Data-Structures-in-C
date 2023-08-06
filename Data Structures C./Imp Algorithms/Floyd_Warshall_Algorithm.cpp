// Floyd Warshall Algorithm - find the shortest path from every vertex in a graph to every other vertex, and store it in a matrix
//Time complexity O(n^3)
#include<iostream>
#include<vector>
#define INF 10000
using namespace std;

void shortest_distance(vector<vector<int>> &matrix, int V)
{
  int i,j,k;
  //Check for negative edges
  for(i=0;i<V;i++)
    {
      if(matrix[i][i]<0)
      {
        cout<<"There are negative weights in the graph"<<endl;
        return;
      }
    }

  //Actual Algorithm
  for(k=0;k<V;k++)
    {
      for(i=0;i<V;i++)
       {
          for(j=0;j<V;j++)
          matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]); 
       }
    }
  for(i=0;i<V;i++)
       {
          for(j=0;j<V;j++)
            { cout<<matrix[i][j]<<" "; }
          cout<<endl;
       }
}
int main()
{
  int V,source,destination,weight;
  cout<<"Enter the number of vertices:"<<endl;
  cin>>V;
  vector<vector<int>> matrix(V, vector<int>(V));
  int i,j;
  cout<<"Enter the weights of edges in graph(If no edge exists, then input -1): "<<endl;
  for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
        {
          cin>>weight;
          if(weight==-1)
            weight = INF;
          matrix[i][j] = weight;
        }
    }
  cout<<"\nThe shortest distance matrix required is:"<<endl;
  shortest_distance(matrix,V); //Storing the answer in the same matrix
  return 0;
}
