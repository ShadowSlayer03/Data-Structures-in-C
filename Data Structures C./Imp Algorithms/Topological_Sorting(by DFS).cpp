// Topological Sort - DFS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node,stack<int>& st,vector<vector<pair<int,int>>> &adj,int vis[])
{
  vis[node] = 1;
  for(auto it: adj[node])
  {
    int adjacentNode = it.first;
    if(vis[adjacentNode]==0)
      dfs(adjacentNode,st,adj,vis);
  }
  st.push(node);
}
void topoSort(vector<vector<pair<int,int>>> &adj, int V)
{
  int* vis = new int[V] {0};
  stack<int> S;
  for(int i=0;i<V;i++)
    {
      if(!vis[i])
        dfs(i,S,adj,vis);
    }

  cout<<"\nOne of the topological ordering is: "<<endl;
  while(!S.empty())
    {
      cout << S.top() << " ";    //Prints the sorted ordering 
      S.pop();
    }
  delete []vis;
}
int main()
{
  int E,V,i;
  int source,destination,weight;
  cout<<"Enter the number of vertices in the graph:"<<endl;
  cin>>V;
  cout<<"Enter the number of edges in the graph:"<<endl;
  cin>>E;
  vector<vector<pair<int,int>>> adj(V);
  for(i=0;i<E;i++)
   {
    cout<<"Enter the graph values in this format: (source destination weight)"<<endl;
     cin>>source>>destination>>weight;
     adj[source].push_back({destination,weight});
    }

  topoSort(adj,V);
  return 0;
}
