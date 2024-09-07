/*
    Tarjan's Algorithm
    It is used to find the bridges in a graph
    A bridge is an edge that if removed, increases the number of connected components in the graph

    we traverse the graph using dfs
    keep a track of their time of insertion and lowest time of insertion it can get from all its adjacent nodes except parent node

    parent always try to get the lowest time of insertion it can get from its children except parent
    after competing dfs parent checks if it can get a lower time of insertion from its children

    it then check if the lowest time of insertion of its children is greater than its own time of insertion
    if yes then it is a bridge since it is the only way to reach that node

    Time Complexity: O(V+E)
    For undirected graph

*/

#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

class Solution
{
private:
    void dfs(int node, int parent, int &timer, vector<vector<int>> &adj, vector<vector<int>> &bridges, vector<bool> &vis, vector<int> &time, vector<int> &low)
    {
        vis[node] = true;
        time[node] = timer++;
        low[node] = time[node];

        for (auto &i : adj[node])
        {
            if (i == parent)
                continue;
            if (vis[i] == false)
            {
                dfs(i, node, timer, adj, bridges, vis, time, low);
                low[node] = min(low[node], low[i]);
                if (low[i] > time[node])
                {
                    bridges.push_back({node, i});
                }
            }
            else
            {
                low[node] = min(low[node], low[i]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);

        for (auto &i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int timer = 1;
        vector<bool> vis(n, 0);
        vector<int> time(n, INT_MAX);
        vector<int> low(n, INT_MAX);
        vector<vector<int>> bridges;

        dfs(0, -1, timer, adj, bridges, vis, time, low);

        return bridges;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    // Solution s;

    // cout << s.checkTwoChessboards("a1", "b2") << endl;
    cout << endl;

    return 0;
}

#endif