#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<int> adj[], vector<bool> &vis, int node, int parent)
    {
        for (auto &n : adj[node])
        {
            if (!vis[n])
            {
                vis[n] = true;
                if (dfs(adj, vis, n, node))
                    return true;
            }
            else if (n != parent)
                return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                if (dfs(adj, vis, i, i))
                    return true;
            }
        }
        return false;
    }
};