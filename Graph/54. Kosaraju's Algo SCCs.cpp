/*
    Kosaraju's Algorithm
    It is used to find the strongly connected components in a graph
    A SCC is a group of nodes in such a way that every node is reachable from every other node in the group

    even if we reverse the direction of the edges, the SCCs remain the unaffected
    :video: https://youtu.be/R6uoSjZ2imo
    :notes: https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

    if we traverse the reverse graph from the node with the highest finishing time, we will get the SCCs

    1. Do a DFS on the graph and store the finishing time of the nodes in a stack
    2. Reverse the graph
    3. Do a DFS on the reversed graph starting from the node with the highest finishing time
    Every component traversed in this DFS is a SCC, make a count of it or store it

    Time Complexity: O(V+E)
    For directed graph
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
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &s)
    {
        vis[node] = 1;

        for (auto &i : adj[node])
        {
            if (vis[i] == 0)
            {
                dfs(i, vis, adj, s);
            }
        }

        s.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (auto &i : adj[node])
        {
            if (vis[i] == 0)
            {
                dfs2(i, vis, adj);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> s;
        vector<int> vis(V, 0);

        // 1. Do a DFS on the graph and store the finishing time of the nodes in a stack
        // O(V+E)
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
                dfs(i, vis, adj, s);
        }

        // 2. Reverse the graph
        // O(V+E)
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            for (auto &node : adj[i])
            {
                adjT[node].push_back(i);
            }
        }

        int scc = 0;
        vis.assign(V, 0);

        // 3. Do a DFS on the reversed graph starting from the node with the highest finishing time
        // O(V+E)
        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (vis[node] == 0)
            {
                dfs2(node, vis, adjT);
                scc++;
            }
        }

        return scc;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    // cout << s.checkTwoChessboards("a1", "b2") << endl;
    cout << endl;

    return 0;
}

#endif