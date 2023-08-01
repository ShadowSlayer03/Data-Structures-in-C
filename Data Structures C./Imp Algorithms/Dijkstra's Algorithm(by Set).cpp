// By using Set
#include<iostream>
#include<vector>
#include<set>
#include<functional>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[],int S)
{
  set<pair<int,int>> st;
  vector<int> dist(V, 1e9);

  dist[S] = 0;
  st.insert({0,S});

  while(!st.empty())
  {
    auto it = *(st.begin());
    int dis = it.first;
    int node = it.second;
    st.erase(it);

    for(auto it:adj[node])
      {
        int adjNode = it[0];
        int adjWeight = it[1];

        if(dis+adjWeight<dist[adjNode])
        {
          if(dist[adjNode]!=1e9)
            st.erase({dist[adjNode],adjNode});
          
            dist[adjNode] = dis+adjWeight;
            st.insert({dist[adjNode],adjNode});
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
