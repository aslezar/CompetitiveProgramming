/*
    Dis Joint Set
    Helps to identify if two nodes are part of same component in O(1)
    we save the ultimate parent of each node
    if two nodes have same ultimate parent then they are part of same component

    to connect two nodes
    we find the ultimate parent of both nodes
    if they are same then they are already connected
    else we connect them by making one of them parent of other

    We can connect two nodes by rank or by size
    By Rank: We connect the node with lower rank to the node with higher rank
    By Size: We connect the node with lower size to the node with higher size
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
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {

        parent.resize(n + 1);

        rank.resize(n + 1);
        for (size_t i = 0; i < parent.size(); i++)
            parent[i] = i;

        size.resize(n + 1, 1);
    }
    int findUltimateParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }
    // T.C. O(4*alpha) = O(1) alpha is the inverse ackermann function
    void unionByRank(int u, int v)
    {
        int p_u = findUltimateParent(u);
        int p_v = findUltimateParent(v);
        if (p_u == p_v)
            return;
        if (rank[p_v] > rank[p_u])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int p_u = findUltimateParent(u);
        int p_v = findUltimateParent(v);
        if (p_u == p_v)
            return;
        if (size[p_v] > size[p_u])
        {
            // join u to v
            parent[p_u] = p_v;
            size[p_v] += size[p_v];
        }
        else
        {
            // join v to u
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    // By Rank
    DisjointSet ds_rank(7);

    ds_rank.unionByRank(1, 2);
    ds_rank.unionByRank(2, 3);
    ds_rank.unionByRank(4, 5);
    ds_rank.unionByRank(6, 7);
    ds_rank.unionByRank(5, 6);

    if (ds_rank.findUltimateParent(3) == ds_rank.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }

    ds_rank.unionByRank(3, 7);

    if (ds_rank.findUltimateParent(3) == ds_rank.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }

    // By Size
    DisjointSet ds_size(7);

    ds_size.unionBySize(1, 2);
    ds_size.unionBySize(2, 3);
    ds_size.unionBySize(4, 5);
    ds_size.unionBySize(6, 7);
    ds_size.unionBySize(5, 6);

    if (ds_size.findUltimateParent(3) == ds_size.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }

    ds_size.unionBySize(3, 7);

    if (ds_size.findUltimateParent(3) == ds_size.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }

    return 0;
}

#endif