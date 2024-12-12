#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
constexpr unsigned int mod = 1e9 + 7;

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int parentOf(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = parentOf(parent[node]);
    }
    void unionT(int u, int v)
    {
        int p_u = parentOf(u);
        int p_v = parentOf(v);

        if (p_u == p_v)
            return;

        if (rank[p_u] < rank[p_v])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_u] = p_v;
            rank[p_v]++;
        }
    }
};

int spanningTree(int V, vector<pair<int, pair<int, int>>> &edges)
{
    int wg = 0;

    sort(edges.begin(), edges.end());
    debug(edges);

    DisjointSet s(V);
    for (auto &edge : edges)
    {
        if (s.parentOf(edge.second.first) != s.parentOf(edge.second.second))
        {
            wg = max(wg, edge.first);
            s.unionT(edge.second.first, edge.second.second);
        }
    }
    return wg;
}
void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<pii> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    if (n == 1)
    {
        cout << 0 el;
        return;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (v[i].first == v[j].first)
            {
                edges.push_back({(abs(v[i].second - v[j].second) + 1) / 2, {i, j}});
            }
            else if (v[i].second == v[j].second)
            {
                edges.push_back({(abs(v[i].first - v[j].first) + 1) / 2, {i, j}});
            }
            else
            {
                int mx = abs(v[i].first - v[j].first);
                int my = abs(v[i].second - v[j].second);
                edges.push_back({max(mx, my), {i, j}});
            }
        }
    }
    // debug(edges);
    int mx = spanningTree(n, edges);
    cout << mx el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}