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

ll sum(ll l, ll r)
{
    // debug(l,r);
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
    // return 1ll * (l + r) * (r - l + 1) / 2;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, k = 0;
    cin >> n >> k;

    ll l = 0, r = n - 1;
    ll ans = INT_MAX;
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        debug(l, r, m);

        ll leftSum = sum(k, k + m);
        ll rightSum = sum(k + m, k + n - 1);

        // debug(l, r, m, leftSum, rightSum);

        if (leftSum < rightSum)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    ans = min(ans, abs(sum(k, k + l) - sum(k + l + 1, k + n - 1)));
    ans = min(ans, abs(sum(k, k + l - 1) - sum(k + l, k + n - 1)));
    cout << ans << endl;
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