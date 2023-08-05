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
  int V,E,source,destination;
  cout<<"Enter the number of vertices"<<endl;
  cin>>V;
  cout<<"Enter the number of edges"<<endl;
  cin>>E;
  vector<vector<int>> adj(V);
  for(int i=0;i<E;i++)
  {
    cout<<"Enter the graph values in this format: (source destination)"<<endl;
    cin>>source>>destination;
    adj[source].push_back(destination);

  topoSort(adj,V);
  return 0;
}
