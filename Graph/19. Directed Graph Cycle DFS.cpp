#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

class Solution
{
public:
    bool isCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &s)
    {

        vis[node] = 1;
        s[node] = 1;

        for (auto &i : adj[node])
        {
            if (!vis[i])
            {
                if (isCycle(i, adj, vis, s))
                    return true;
            }
            else if (s[i])
                return true;
        }

        s[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool
    isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> s(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycle(i, adj, vis, s))
                    return true;
            }
        }
        return false;
    }
};