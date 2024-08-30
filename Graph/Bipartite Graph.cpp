#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        //BFS
        vector<int> vis(V, 0);
        for (size_t i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while (!q.empty())
                {
                    auto front = q.front();
                    q.pop();
                    for (auto &i : adj[front])
                    {
                        if (vis[i] == 0)
                        {
                            vis[i] = -vis[front];
                            q.push(i);
                        }
                        else if (vis[i] == vis[front])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isBipartiteDFS(int V, vector<int> adj[])
    {
        //DFS
        vector<int> vis(V, 0);
        for (size_t i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                stack<int> s;
                s.push(i);
                vis[i] = 1;

                while (!s.empty())
                {
                    auto front = s.top();
                    s.pop();
                    for (auto &i : adj[front])
                    {
                        if (vis[i] == 0)
                        {
                            vis[i] = -vis[front];
                            s.push(i);
                        }
                        else if (vis[i] == vis[front])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
