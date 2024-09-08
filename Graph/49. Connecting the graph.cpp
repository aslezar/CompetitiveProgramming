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
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int parentOf(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = parentOf(parent[u]);
    }
    void unionR(int u, int v)
    {
        int pu = parentOf(u);
        int pv = parentOf(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edges)
    {
        if (edges.size() < n - 1)
            return -1;

        DisjointSet ds(n);
        for (auto &edge : edges)
        {
            ds.unionR(edge[0], edge[1]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parentOf(i) == i)
                cnt++;
        }
        return cnt - 1;
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