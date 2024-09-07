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
    Space Complexity: O(3*(V+E))
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
    void dfs(int node, int parent, int &timer, vector<int> adj[], vector<int> &mark, vector<int> &tin, vector<int> &low, vector<int> &vis)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        int child = 0;
        for (auto &i : adj[node])
        {
            if (i == parent)
                continue;
            if (vis[i] == 0)
            {
                dfs(i, node, timer, adj, mark, tin, low, vis);
                low[node] = min(low[node], low[i]);
                if (parent != -1 && low[i] >= tin[node])
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[i]);
            }
        }

        if (parent == -1 and child > 1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V);
        vector<int> mark(V);
        vector<int> tin(V);
        vector<int> low(V);

        int timer = 1;

        for (int i = 0; i < V; i++)
        {
            if (vis[i])
                dfs(0, -1, timer, adj, mark, tin, low, vis);
        }

        vector<int> ans;
        for (int i = 0; i < mark.size(); i++)
            if (mark[i] == 1)
                ans.push_back(i);
        if (ans.size() == 0)
            return {-1};
        return ans;
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