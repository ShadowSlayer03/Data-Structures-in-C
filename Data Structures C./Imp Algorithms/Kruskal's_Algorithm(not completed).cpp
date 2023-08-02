#include<iostream>
#include<vector>
#include<algorithm>
#define edge pair<int,int>
using namespace std;

vector<pair<int,edge>> G;
vector<pair<int,edge>> T;

void AddWeightedEdge(int weight, int src, int dest)
{
    G.push_back(make_pair(weight,edge(src,dest)));
}

void union_set(int u,int v,int* parent)
{
    parent[u] = parent[v];
}

int find_set(int i,int* parent)
{
    if(i==parent[i])
        return i;
    else
        return find_set(parent[i],parent);
}
void kruskal(int* parent)
{
  int i,vRep,uRep;
  sort(G.begin(),G.end());
  for(i=0;i<G.size();i++)
  {
      uRep = find_set(G[i].second.first,parent);
      vRep = find_set(G[i].second.second,parent);
      if(uRep!=vRep)
      {
          T.push_back(G[i]);
          union_set(uRep,vRep,parent);
      }
  }
}

void print(int V)
{
    for(int i=0;i<V;i++)
    {
    cout<<"From "<<G[i].second.first<<"to "<<G[i].second.second<<": "<<endl;
    cout<<"Weight: "<<G[i].first<<endl;
    }
}
int main()
{
int V;
cout<<"Enter the number of vertices: "<<endl;
cin>>V;
int parent[V];
for(int i=0;i<V;i++)
parent[i] = i;
G.clear();
T.clear();

  G.AddWeightedEdge(4,0,1);  //(weight,src,dest)
  G.AddWeightedEdge(4,0,2);
  G.AddWeightedEdge(2,1,2);
  G.AddWeightedEdge(4,1,0);
  G.AddWeightedEdge(4,2,0);
  G.AddWeightedEdge(2,2,1);
  G.AddWeightedEdge(3,2,3);
  G.AddWeightedEdge(2,2,5);
  G.AddWeightedEdge(4,2,4);
  G.AddWeightedEdge(3,3,2);
  G.AddWeightedEdge(3,3,4);
  G.AddWeightedEdge(4,4,2);
  G.AddWeightedEdge(3,4,3);
  G.AddWeightedEdge(2,5,2);
  G.AddWeightedEdge(3,5,4);
  
  kruskal(parent);
  print(V);
return 0;
}
