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

void dfs(int node, int parent, vii &t, vi &depth, vi &maxDepth)
{
    maxDepth[node] = depth[node];
    for (int child : t[node])
    {
        if (child != parent)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node, t, depth, maxDepth);
            maxDepth[node] = max(maxDepth[node], maxDepth[child]);
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vii t(n + 1);
    for (size_t i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    vi depth(n + 1, 0), maxDepth(n + 1, 0);
    dfs(1, 0, t, depth, maxDepth);

    debug(depth);
    debug(maxDepth);

    ll maxD = *max_element(all(maxDepth));

    vi count_depth(maxD + 1, 0);
    vi count_maxDepth(maxD + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        count_depth[depth[i]]++;
        count_maxDepth[maxDepth[i]]++;
    }

    ll acc = n;
    ll acc2 = n;
    for (int i = 0; i <= maxD; i++)
    {
        acc -= count_depth[i];
        count_depth[i] = acc;

        int index = maxD - i;
        acc2 -= count_maxDepth[index];
        count_maxDepth[index] = acc2;
    }
    debug(count_depth);
    debug(count_maxDepth);

    ll ans = INT_MAX;

    for (int d = 0; d <= maxD; d++)
    {
        ans = min(ans, count_depth[d] + count_maxDepth[d]);
    }

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