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
    ll n = 0;
    cin >> n;

    vi a(n);
    input(a, n);

    vi b(n);
    input(b, n);

    vi g;

    int mn = INT_MAX;

    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= b[i])
        {
            mn = min(mn, a[i] - b[i]);
            cost += b[i];
        }
        // else if (a[i] == b[i])
        // {
        // }
        else
        {
            g.push_back(b[i] - a[i]);
            cost += a[i];
        }
    }
    debug(g);
    debug(cost);
    if (g.size() == 1)
    {
        cost += min(g[0], mn);
    }

    cout << cost el;
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