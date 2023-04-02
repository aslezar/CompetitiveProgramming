#include <vector>
using namespace std;
// Input adjancery matrix to form graph
void input(const int n, const vector<vector<int>> &edges)
{
    vector<vector<int>> g(n);
    for (auto &&i : edges)
    {
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
}
// DFS
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    visited[src] = true;
    for (auto it = adj[src].begin(); it != adj[src].end(); ++it)
        if (!visited[*it])
            dfs(adj, visited, *it);
}

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    // DFS for container wise traversal
    // Invoking function
    // int noofcontainer = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!v[i])
    //     {
    //         dfs(g, v, i, nodes);
    //         noofcontainer++;
    //     }
    // }
    visited[src] = true;
    for (auto it = adj[src].begin(); it != adj[src].end(); ++it)
        if (!visited[*it])
            dfs(adj, visited, *it);
}