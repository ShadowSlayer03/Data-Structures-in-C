// Dijkstra by Priority Queues
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj,int V, int S)
{
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(V,1e9);

  dist[S] = 0;
  pq.push({0,S});

  while(!pq.empty())
    {
      int wt = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for(auto it:adj[node])
        {
          int adjNode = it.first;
          int adjWt = it.second;
          if(wt+adjWt<dist[adjNode])
          {
            dist[adjNode] = wt+adjWt;
            pq.push({dist[adjNode],adjNode});
          }
        }
    }
  return dist;
}
int main()
{
  int V,E,S,source,destination,weight;
  cout<<"Enter the number of vertices in the graph: "<<endl;
  cin>>V;
  cout<<"Enter the number of edges: "<<endl;
  cin>>E;
  vector<vector<pair<int,int>>> adj(V);
  cout<<"Enter the graph in this format(source destination weight)";
  for(int i=0;i<E;i++)
    {
      cin>>source>>destination>>weight;
      adj[source].push_back({destination,weight});
      adj[destination].push_back({source,weight});
    }
  cout<<"Enter the source vertex:"<<endl;
  cin>>S;
  vector<int> res = dijkstra(adj,V,S);
  for(int i=0;i<V;i++)
    cout<<"Shortest distance from source to vertex "<<i<<" is "<<res[i]<<endl;
  return 0;
}
