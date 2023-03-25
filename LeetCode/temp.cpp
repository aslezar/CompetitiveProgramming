#include <vector>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src, long long &nodes)
    {
        visited[src] = true;
        nodes++;
        for (auto &&i : adj[src])
            if (!visited[i])
                dfs(adj, visited, i, nodes);
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (auto &&i : edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        long long ans = 0;
        vector<bool> v(n, false);
        for (int i = 0; i < n; i++)
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