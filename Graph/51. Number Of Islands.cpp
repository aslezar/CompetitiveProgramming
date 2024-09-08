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
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int parentOf(int u)
    {
        if (u == parent[u])
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
            // equal case
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {

        int rowSize = 0;
        int colSize = 0;
        for (auto &i : stones)
        {
            rowSize = max(rowSize, i[0]);
            colSize = max(colSize, i[1]);
        }

        DisjointSet ds(rowSize + colSize + 2);
        unordered_set<int> s;
        for (auto &stone : stones)
        {
            ds.unionR(stone[0], rowSize + stone[1] + 1);
            s.insert(stone[0]);
            s.insert(rowSize + stone[1] + 1);
        }
        int cc = 0;
        for (auto &i : s)
        {
            if (ds.parentOf(i) == i)
            {
                cc++;
            }
        }
        return n - cc;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    return 0;
}

#endif