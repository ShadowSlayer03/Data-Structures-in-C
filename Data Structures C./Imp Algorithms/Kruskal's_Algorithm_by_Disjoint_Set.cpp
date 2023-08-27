// Kruskal's Algorithm by using Disjoint Set data structure
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;  

vector<int> parent,size;

void initialize(int n)
{
  size.resize(n+1);
  parent.resize(n+1);
  for(int i=0;i<=n;i++)
    {
    parent[i] = i;
    size[i] = 1;
    }
}
int findUParent(int node)
{
  if(parent[node]==node)
    return node;
  else
    return parent[node]= findUParent(parent[node]);
}

void union_by_size(int u,int v)
{
  int u_ultParent = findUParent(u);
  int v_ultParent = findUParent(v);

  if(u_ultParent == v_ultParent)
    return;
  
    if(size[u_ultParent]<size[v_ultParent])
    {
      parent[u_ultParent] = v_ultParent;
      size[v_ultParent] += size[u_ultParent];
    }
    else
    {
      parent[v_ultParent] = u_ultParent;
      size[u_ultParent] += size[v_ultParent];
    }
}

void kruskal(vector<vector<pair<int,int>>>& adj,int V)
{
  vector<pair<int,pair<int,int>>> edges;
  list<pair<int,int>> mstEdges;
  
  for(int i=0;i<V;i++)
    {
      for(auto it:adj[i])
        {
          int src = i;
          int dest = it.first;
          int wt = it.second;

          edges.push_back({wt,{src,dest}});
        }
    }
  
  initialize(V);
  sort(edges.begin(),edges.end());
  int mstWt = 0;

  for(auto it:edges)
    {
      int wt = it.first;
      int u = it.second.first;
      int v = it.second.second;

      if(findUParent(u)!=findUParent(v))
      {
        mstWt += wt;
        union_by_size(u,v);
        mstEdges.push_back({u, v});
      }
    }
  cout<<"The sum of weights in the min spanning tree is "<<mstWt<<endl;

  cout << "Minimum Spanning Tree Edges (w/ cost):\n";
    for (const auto &edge : mstEdges)
    {
        cout << "[" << edge.first << "]---[" << edge.second << "]\n";
    }
}
int main()
{
  int V,E,source,dest,wt;
  cout<<"Enter the number of vertices in the graph:"<<endl;
  cin>>V;
  cout<<"Enter the number of edges in the graph:"<<endl;
  cin>>E;
  vector<vector<pair<int,int>>> adj(V);
  cout << "Enter edges and their weights in the format (source destination weight):\n";
  for(int i=0;i<E;i++)
    {
      cin>>source>>dest>>wt;
      adj[source].push_back({dest,wt});
      adj[dest].push_back({source,wt});
    }

  kruskal(adj,V);
  return 0;
}
