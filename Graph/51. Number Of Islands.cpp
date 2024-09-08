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
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int parentOf(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = parentOf(parent[u]);
    }
    void unionR(int u, int v)
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
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, const vector<vector<int>> &operators)
    {
        vector<int> ans;

        DisjointSet ds(n * m);

        const vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> mat(n, vector<int>(m, 0));

        int cnt = 0;

        for (auto &op : operators)
        {
            int i = op[0];
            int j = op[1];

            if (mat[i][j] == 1)
            {
                ans.push_back(cnt);
                continue;
            }

            mat[i][j] = 1;
            cnt++;

            for (auto &d : delta)
            {

                // adjacent node indexes
                int x = i + d.first;
                int y = j + d.second;

                if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                {
                    int nodeNo = i * m + j;
                    int adjNodeNo = x * m + y;
                    if (ds.parentOf(nodeNo) != ds.parentOf(adjNodeNo))
                    {
                        cnt--;
                        ds.unionR(nodeNo, adjNodeNo);
                    }
                }
            }
            // int scc = 0;
            // for (int k = 0; k < m * n; k++)
            // {
            //     if (mat[k / m][k % m] == 1 && ds.parentOf(k) == k)
            //     {
            //         scc++;
            //     }
            // }
            ans.push_back(cnt);
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // n = 4
    // m = 5
    // k = 4
    // A = {{1,1},{0,1},{3,3},{3,4}}

    // auto ans = s.numOfIslands(4, 5, {{1, 1}, {0, 1}, {3, 3}, {3, 4}});
    // debug(ans);

    auto ans2 = s.numOfIslands(5, 20, {{0, 3}, {4, 7}, {3, 17}, {3, 1}, {1, 16}, {4, 18}, {1, 16}, {3, 14}, {3, 6}, {4, 11}, {4, 4}, {1, 9}, {4, 9}, {0, 1}, {2, 3}, {0, 15}, {0, 2}, {4, 11}, {3, 18}, {3, 16}, {4, 11}, {2, 3}, {0, 2}, {1, 0}, {4, 13}, {1, 11}, {0, 3}, {1, 16}, {2, 19}, {1, 3}, {4, 15}, {0, 18}, {2, 8}, {2, 17}});

    debug(ans2);
    cout << endl;

    return 0;
}

#endif