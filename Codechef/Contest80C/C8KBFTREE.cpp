#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

void addEdge(vector<pair<int, int>> adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int, int>> adj[], int V)
{
    map<int, pair<int, int>> m;
    m.clear();
    int v, w;
    for (int u = 1; u <= V; u++)
    {
        int xorr = 0;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            xorr = xorr ^ w;
            auto findd = m.find(xorr);
            if (findd != m.end())
            {
                cout << u ws << v ws << findd->second.first ws << findd->second.second el;
                return;
            }
            else
                m[xorr] = {u, v};
        }
    }
    cout << -1 el;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        vector<pair<int, int>> adj[n + 1];
        adj->clear();
        for (int i = 0; i < n - 1; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            addEdge(adj, a, b, c);
        }
        printGraph(adj, n);
    }
    return 0;
}