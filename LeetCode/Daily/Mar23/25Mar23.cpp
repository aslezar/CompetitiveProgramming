#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int src, long long &nodes)
    {
        visited[src] = true;
        ++nodes;
        for (auto it = adj[src].begin(); it != adj[src].end(); ++it)
            if (!visited[*it])
                dfs(adj, visited, *it, nodes);
    }
    long long countPairs(const int n, const vector<vector<int>> &edges)
    {
        long long ans = 0;
        vector<vector<int>> g(n);
        vector<bool> v(n, false);
        for (auto &&i : edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for (size_t i = 0; i < n; ++i)
        {
            long long nodes = 0;
            if (!v[i])
            {
                dfs(g, v, i, nodes);
                ans += nodes * (n - nodes);
            }
        }
        return ans / 2;
    }
};
int main()
{
    return 0;
}