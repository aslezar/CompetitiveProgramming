/*
    Disjoint Set Kruskal's Algorithm
    We have to find the MST of the graph

    we traverse all the edges in sorted order of their edge weights
    if two nodes connected by edge is already a part of same component we discard the edge
    else we add the edge to our MST
    Since we are traversing the edges in sorted order of their weights
    we are sure that the edge we are adding is the minimum edge that connects two components
*/

#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int parentOf(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = parentOf(parent[node]);
    }
    void unionT(int u, int v)
    {
        int p_u = parentOf(u);
        int p_v = parentOf(v);

        if (p_u == p_v)
            return;

        if (rank[p_u] < rank[p_v])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_u] = p_v;
            rank[p_v]++;
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int wg = 0;
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto &edge : adj[i])
            {
                edges.push_back({edge[1], {i, edge[0]}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet s(V);
        for (auto &edge : edges)
        {
            debug(s.parentOf(edge.second.first));
            debug(s.parentOf(edge.second.second));
            if (s.parentOf(edge.second.first) != s.parentOf(edge.second.second))
            {
                debug(wg);
                wg += edge.first;
                s.unionT(edge.second.first, edge.second.second);
            }
        }
        return wg;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    // 3 3
    // 0 1 5
    // 1 2 3
    // 0 2 1

    vector<vector<int>> adj[3];
    adj[0].push_back({1, 5});
    adj[1].push_back({2, 3});
    adj[0].push_back({2, 1});
    cout << s.spanningTree(3, adj);
    cout << endl;

    return 0;
}

#endif