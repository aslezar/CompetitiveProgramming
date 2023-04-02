#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (auto &&i : edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int c = 0;
        for (auto &&i : g)
        {
            cout << c++ << ':' << ' ';
            for (auto &&j : i)
            {
                cout << j ws;
            }
            cout el;
        }
        int ans = INT_MAX;
        // BFS

        // vector<bool> v(n, 0);
        // queue<int> q;

        // for (size_t i = 0; i < n; i++)
        // {
        //     q.push(i);
        //     if (!v[i])
        //     {
        //         while (!q.empty())
        //         {
        //             v[i] = 1;
        //             for (auto &&i : g[q.front()])
        //             {
        //                 if (!v[i])
        //                 {
        //                     cout << i << ' ';
        //                     q.push(i);
        //                 }
        //             }
        //             q.pop();
        //         }
        //     }
        // }
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        vector<int> dist(n, -1);
        queue<int> q;

        int shortest_cycle = n + 1;

        for (int start_node = 0; start_node < n; start_node++)
        {
            if (!visited[start_node])
            {
                q.push(start_node);
                visited[start_node] = true;
                dist[start_node] = 0;
                while (!q.empty())
                {
                    int curr_node = q.front();
                    q.pop();
                    for (auto neighbor : g[curr_node])
                    {
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            dist[neighbor] = dist[curr_node] + 1;
                            parent[neighbor] = curr_node;
                            q.push(neighbor);
                        }
                        else if (neighbor != parent[curr_node])
                        { // cycle detected
                            int cycle_length = dist[curr_node] + dist[neighbor] + 1;
                            shortest_cycle = min(shortest_cycle, cycle_length);
                        }
                    }
                }
            }
        }
        return shortest_cycle <= n ? shortest_cycle : -1;
    }
};
class Solution2
{
public:
    int ans = INT_MAX;

    void bfs(int src, vector<int> adj[], int n)
    {
        vector<int> distance(n, (1e9));
        vector<int> parent(n, -1);

        queue<int> q;
        distance[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto neigh : adj[node])
            {
                if (distance[neigh] == (int)(1e9))
                {
                    distance[neigh] = 1 + distance[node];
                    parent[neigh] = node;
                    q.push(neigh);
                }
                else if (parent[node] != neigh && parent[neigh] != node)
                    ans = min(ans, distance[neigh] + distance[node] + 1);
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            bfs(i, adj, n);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
int main()
{
    Solution ans;
    vector<vector<int>> a = {{0, 1},
                             {1, 2},
                             {2, 0},
                             {3, 4},
                             {4, 5},
                             {5, 6},
                             {6, 3}};
    cout << ans.findShortestCycle(7, a);
    return 0;
}