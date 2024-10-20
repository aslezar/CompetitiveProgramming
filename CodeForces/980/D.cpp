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
constexpr unsigned int mod = 1e9 + 7;

vector<int> dijkstra(int N, vector<vector<pair<int, int>>> &adj, int S = 1)
{
    // T.C. E*log(V)

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, LLONG_MAX);

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        auto top = pq.top();
        int distance = top.first;
        int node = top.second;
        pq.pop();

        if (dist[node] < distance)
            continue;

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int edgeWg = it.second;

            if (distance + edgeWg < dist[adjNode])
            {
                dist[adjNode] = distance + edgeWg;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].first;
    for (int i = 1; i <= n; i++)
        cin >> v[i].second;

    vi sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = v[i].first + sum[i - 1];
    }

    // vector<vector<int>> edges(n + 1, vector<int>(n + 1));
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (v[i].second != i - 1)
            adj[i].push_back({v[i].second, v[i].first});
        if (i - 2 >= 0)
            adj[i].push_back({i - 1, 0});
    }

    auto dist = dijkstra(n, adj, 1);
    debug(dist);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int curAns = sum[i] - dist[i];
        ans = max(ans, curAns);
    }
    cout << ans el;
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