#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const int maxn = 1e5 + 4;

int n;
vector<pair<int, int>> adj[maxn];
int dist[maxn], vis[maxn], parent[maxn];
map<int, pair<int, int>> mp;

void dfs(int u, int d)
{
    vis[u] = 1;
    dist[u] = d;
    for (auto p : adj[u])
    {
        int v = p.first, w = p.second;
        if (!vis[v])
        {
            parent[v] = u;
            dfs(v, d ^ w);
        }
        else if (v != parent[u])
        {
            int x = d ^ w ^ dist[v];
            if (mp.find(x) != mp.end())
            {
                int a = u, b = v, c = mp[x].first, d = mp[x].second;
                if (a > b)
                    swap(a, b);
                if (c > d)
                    swap(c, d);
                if (a < c && c < b && b < d)
                {
                    cout << a ws << b ws << c ws << d el;
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--)
    {

        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dfs(1, 0);
    }
    return 0;
}
