#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

class Disjointset
{
    vector<int> rank, parent;

public:
    Disjointset(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int parentOf(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = parentOf(parent[u]);
    }
    void unionT(int u, int v)
    {
        int pu = parentOf(u);
        int pv = parentOf(v);
        if (pu == pv)
            return;
        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        Disjointset ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j])
                {
                    ds.unionT(i, j);
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < V; i++)
        {
            s.insert(ds.parentOf(i));
        }
        return s.size();
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