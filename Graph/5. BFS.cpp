#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // T.C. O(N+2E) = O(N+E)
        // S.C. O(3*N) = O(N)
        vector<int> ans;

        vector<bool> vis(V, false);
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (vis[i])
                continue;
            q.push(i);
            vis[i] = true;

            while (!q.empty())
            {
                auto node = q.front();
                q.pop();
                ans.push_back(node);

                for (auto &n : adj[node])
                {
                    if (!vis[n])
                    {
                        q.push(n);
                        vis[n] = true;
                    }
                }
            }
        }
        return ans;
    }
};