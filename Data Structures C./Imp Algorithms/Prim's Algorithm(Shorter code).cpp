#include<iostream>
#include<vector>
#include<queue>
#include<list>  // Include the list header
using namespace std;

void prim(vector<vector<pair<int, int>>> &adj, int V)
{
    int* vis = new int[V] {0};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int sum = 0;
    
    // Create a list to store MST edges
    list<pair<int, int>> mstEdges;

    pq.push({0, 0});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;
            if (!vis[adjNode])
            {
                pq.push({edgeWt, adjNode});
                mstEdges.push_back({node, adjNode});  // Store MST edge
            }
        }
    }

    cout << "The total cost of the minimum spanning tree is " << sum << endl;

    // Print and store MST edges
    cout << "Minimum Spanning Tree Edges (w/ cost):\n";
    for (const auto &edge : mstEdges)
    {
        cout << "[" << edge.first << "]---[" << edge.second << "]\n";
    }

    delete[] vis;
}

int main()
{
    int V, E, source, destination, weight;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges and their weights in the format (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> source >> destination >> weight;
        adj[source].push_back({destination, weight});
        adj[destination].push_back({source, weight});  // Adding for an undirected graph
    }
    
    prim(adj, V);
    return 0;
}
