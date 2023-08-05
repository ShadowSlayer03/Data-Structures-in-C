#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S)
{
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    dist[S] = 0;
    st.insert({0, S});

    while (!st.empty())
    {
        auto it = st.begin();
        int dis = it->first;
        int node = it->second;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWeight = it.second;

            if (dis + adjWeight < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    auto it = st.find({dist[adjNode], adjNode});
                    if (it != st.end())
                        st.erase(it);
                }

                dist[adjNode] = dis + adjWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int V, E, S;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges and their weights in the format 'source destination weight':\n";
    for (int i = 0; i < E; i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        adj[source].push_back({destination, weight});
    }

    cout << "Enter source vertex: ";
    cin >> S;

    vector<int> res = dijkstra(V, adj, S);

    cout << "Shortest distances from source vertex " << S << " are: ";
    for (int i = 0; i < V; i++)
        cout << res[i] << " ";

    return 0;
}
