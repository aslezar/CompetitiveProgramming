#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                queue<pair<int, int>> q;

                q.push({i, i});
                vis[i] = true;

                while (!q.empty())
                {
                    auto front = q.front();
                    q.pop();

                    for (auto &n : adj[front.first])
                    {
                        if (!vis[n])
                        {
                            vis[n] = true;
                            q.push({n, front.first});
                        }
                        else if (n != front.second)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};