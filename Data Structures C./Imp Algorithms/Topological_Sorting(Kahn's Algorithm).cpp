//Topological Sort- Kahn's Algorithm(Removal of vertices with indegree 0)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topoSort(vector<vector<int>> &adj,int V)
{
  int* indegree = new int[V] {0};
  for(int i=0;i<V;i++)
    {
      for(auto it:adj[i])
        {
          indegree[it]++;
        }
    }

  queue<int> q;
  for(int i=0;i<V;i++)
    {
      if(indegree[i]==0)
        q.push(i);
    }

  vector<int> topo;
  while(!q.empty())
    {
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for(auto it:adj[node])
        {
          indegree[it]--;
          if(indegree[it]==0) q.push(it);
        }
    }

  for(auto j:topo)
    cout<<j<<" ";
  delete []indegree;
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
  }

  topoSort(adj,V);
  return 0;
}
