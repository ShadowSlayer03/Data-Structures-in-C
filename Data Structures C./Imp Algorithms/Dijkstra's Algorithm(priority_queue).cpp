// By using Priority Queues
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[],int S)
{
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<int> dist(V,1e9);

  dist[S] = 0;
  pq.push({0,S});

  while(!pq.empty())
    {
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for(auto it:adj[node])
        {
          int adjNode = it[0];
          int adjWeight = it[1];

          if(dis+adjWeight<dist[adjNode])
          {
             dist[adjNode] = dis+adjWeight;
             pq.push({dist[adjNode],adjNode});
          }
        }
    }
  return dist;
}
int main()
{
    int V = 3;
    vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int i=0; 
    int S;
    cout<<"Enter source vertex:"<<endl;
    cin>>S;
    vector<int>res = dijkstra(V,adj,S);
    for(i=0;i<V;i++)
        cout<<res[i]<<" ";
  return 0;
}
