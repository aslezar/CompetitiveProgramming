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
    ll n = 0;
    cin >> n;

    ll q = 0;
    cin >> q;

    vi v(n);
    vi d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    debug(v);
    for (int i = 1; i < n; i++)
    {
        d[i] = d[i - 1] + abs(v[i] - v[i - 1]);
    }
    debug(d);

    for (int qq = 0; qq < q; qq++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        ll diff = d[r] - d[l];

        if (diff <= k)
        {
            cout << "0\n";
            continue;
        }

        ll sortDiff = abs(v[r] - v[l]);
        ll ans = 0;

        assert((diff - sortDiff) % 2 == 0);
        // if (k < sortDiff)
        // {
        //     ans += (diff - sortDiff) / 2;
        //     ans += (sortDiff - k);
        // }
        // else
        // {
        //     ans += (diff - k + 1) / 2;
        // }
        if (k >= sortDiff)
        {
            ll diffBetweenSortedAndUnSorted = diff - k;
            ans = (diffBetweenSortedAndUnSorted) / 2;
            ans += (diffBetweenSortedAndUnSorted & 1);
        }
        // else if (k == sortDiff)
        // {
        //     ans = (diff - sortDiff) / 2;
        // }
        else
        {
            ans = (diff - sortDiff) / 2;
            ans += (sortDiff - k) / 1;
        }
        cout << ans << endl;
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