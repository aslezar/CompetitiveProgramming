#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, const vector<int> adj[])
    {
        // T.C. O(N+2*E) = O(N+E)
        // S.C. O(3*N) = O(N)
        vector<int> ans;
        vector<bool> vis(V);
        helper(0, adj, vis, ans);
        return ans;
    }
    void helper(int node, const vector<int> adj[], vector<bool> &vis, vector<int> &ans)
    {
        vis[node] = true;
        ans.push_back(node);
        for (auto &n : adj[node])
        {
            if (!vis[n])
            {
                helper(n, adj, vis, ans);
            }
        }
    }
};