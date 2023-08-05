//BFS(Breadth First Search) - Similar to Level order traversal
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> adj, int V)
{
  int* vis = new int[V] {0};
  queue<int> q;
  vis[0] = 1;
  q.push(0);
  vector<int> bfs;
  while(!q.empty())
    {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      for(auto it: adj[node])
        {
          if(!vis[it])
          {
            vis[it] =1;
            q.push(it);
          }
        }
    }

  for(int j:bfs)
    cout<<j<<" ";
  delete []vis;
}
int main()
{
  int V,E,source,destination;
  cout<<"Enter the number of vertices"<<endl;
  cin>>V;
  cout<<"Enter the number of edges"<<endl;
  cin>>E;
  vector<vector<int>> adj(V);
  for(int i=0;i<V;i++)
    {
      cout<<"Enter the graph in the format(source destination): "<<endl;
      cin>>source>>destination;
      adj[source].push_back(destination);
    }

  bfs(adj,V);
  return 0;
}
