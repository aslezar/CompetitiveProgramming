/*
    Prim's Algorithm
    We have to find the MST of the graph

    To find the mst we start from a node
    we add the node to our mst
    we then add all the edges of the node to a priority queue
    if the edge is already a part of mst we discard it
    else we add the edge to our mst

    since we are using priority queue we are sure that the edge we are adding is the minimum edge that connects the mst to the rest of the graph

    T.C. E*logE
*/

// MST is for weighted, connected and undirected graph

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
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // T.C. E*logE

        // To get the edges of minimum spanning tree, you also had to store the parent of the node from where it pushed into the queue

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);

        pq.push({0, 0});
        int sum = 0;

        // E
        while (!pq.empty())
        {
            // log E
            auto top = pq.top();
            pq.pop();

            int edWg = top.first;
            int node = top.second;

            if (vis[node] == 1)
            {
                continue; // Skip this node, already visited
            }
            vis[node] = 1;
            sum += edWg;

            // E *logE
            for (auto &edge : adj[node])
            {
                int edgeNode = edge[0];
                int edgeWg = edge[1];

                if (vis[edgeNode] == 0)
                {
                    pq.push({edgeWg, edgeNode});
                }
            }
        }
        // in total : ElogE+ElogE = ElogE
        return sum;
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