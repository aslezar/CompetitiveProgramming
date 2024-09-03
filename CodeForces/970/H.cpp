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

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, q = 0;
    cin >> n >> q;
    vi v(n);
    vi c(n + 1);
    FOR(i, 1, n)
    {
        cin >> v[i - 1];
        c[v[i - 1]]++;
    }
    // debug(c);
    FOR(i, 1, n)
    {
        c[i] += c[i - 1];
    }
    // debug(c);
    vi ans(n + 1);
    FOR(x, 1, n)
    {
        ll l = 0, r = x;
        while (l < r)
        {
            ll m = l + (r - l) / 2;
            ll cnt = c[m];
            for (ll k = 1; k * x <= n; k++)
            {
                cnt += (c[min(k * x + m, n)] - c[k * x - 1]);
            }
            if (cnt >= n / 2 + 1)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        ans[x] = l;
    }
    FOR(qq, 1, q)
    {
        ll x;
        cin >> x;

        cout << ans[x] << " ";
    }
    cout << endl;
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