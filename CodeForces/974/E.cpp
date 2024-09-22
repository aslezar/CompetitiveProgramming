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
#define set_bits __builtin_popcount

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S, set<int> &horses)
{
    // T.C. E*log(V)

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<ll> dist(V + 1, LLONG_MAX);

    dist[S] = 0;
    pq.push({0, S, 0});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int distance = top[0];
        int node = top[1];
        int isTravelHorse = top[2];

        int isNodeHorse = horses.count(node);

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int edgeWg = it.second;

            if (isTravelHorse == 1 || isNodeHorse == 1)
                edgeWg /= 2;

            if (distance + edgeWg <= dist[adjNode])
            {
                dist[adjNode] = min(dist[adjNode], distance + edgeWg);
                pq.push({dist[adjNode], adjNode, isTravelHorse || isNodeHorse});
            }
            else if (isTravelHorse == 0 && isNodeHorse == 1)
            {
                pq.push({distance + edgeWg, adjNode, isTravelHorse || isNodeHorse});
            }
        }
    }

    return dist;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, m, h;
    cin >> n >> m >> h;

    set<int> horses;
    for (size_t i = 0; i < h; i++)
    {
        ll x;
        cin >> x;
        horses.insert(x);
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    ll u, v, w;
    for (size_t i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dMartin = dijkstra(n, adj, 1, horses);
    vector<int> dRobin = dijkstra(n, adj, n, horses);

    debug(dMartin);
    debug(dRobin);

    ll ans = LLONG_MAX;
    for (size_t i = 1; i <= n; i++)
    {
        ans = min(ans, max(dMartin[i], dRobin[i]));
    }
    if (ans == LLONG_MAX)
        ans = -1;
    cout << ans << '\n';
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