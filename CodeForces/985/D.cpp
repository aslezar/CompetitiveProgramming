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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, m = 0;
    cin >> n >> m;

    vii ans;

    vi edge(n + 1, 0);
    int u = 0, v = 0;
    for (int t = 0; t < m; t++)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (u > 1)
            ans.push_back({1, u, v});
        edge[u] ^= 1;
        edge[v] ^= 1;
    }
    int p = 0;
    for (int i = 2; i <= n; i++)
    {
        if (edge[i])
            p = i;
    }

    if (p != 0)
    {
        for (int i = 2; i <= n; i++)
        {
            if (edge[i] == 0)
            {
                ans.push_back({1, p, i});
                p = i;
            }
        }
    }

    cout << ans.size() el;
    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
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