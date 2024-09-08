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
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
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
            size[p_v] += size[p_u];
        }
        else
        {
            // join v to u
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
    int sizeOf(int parent)
    {
        return size[parent];
    }
};

class Solution
{
public:
    int MaxConnection(const vector<vector<int>> &grid)
    {
        int n = grid.size();

        DisjointSet ds(n * n);

        const vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (auto &d : delta)
                    {
                        int x = i + d.first;
                        int y = j + d.second;

                        int nodeNo = i * n + j;
                        int adjNodeNo = x * n + y;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        int ans = 0;
        // this is important if grid doesnot containe any zero
        for (int c = 0; c < n * n; c++)
        {
            ans = max(ans, ds.sizeOf(ds.findUltimateParent(c)));
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int newSize = 1; // for current node
                    unordered_set<int> parents;
                    for (auto &d : delta)
                    {
                        int x = i + d.first;
                        int y = j + d.second;

                        int nodeNo = i * n + j;
                        int adjNodeNo = x * n + y;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            parents.insert(ds.findUltimateParent(adjNodeNo));
                        }
                    }

                    for (auto &p : parents)
                    {
                        newSize += ds.sizeOf(p);
                    }

                    ans = max(ans, newSize);
                }
            }
        }

        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

#endif