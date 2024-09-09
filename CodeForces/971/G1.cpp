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

#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll k, q;
    cin >> k >> q;
    vi v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] -= i;
    }
    m[0] = n;
    debug(v);

    unordered_map<int, int> f;
    debug(m);
    for (int i = 0; i < k - 1; i++)
    {
        auto &freq = f[v[i]];
        m[freq]--;
        if (m[freq] == 0)
            m.erase(freq);
        freq++;
        m[freq]++;
    }
    vi ans(n + 1);
    for (int i = k - 1; i < n; i++)
    {
        auto &freq = f[v[i]];
        m[freq]--;
        if (m[freq] == 0)
            m.erase(freq);
        freq++;
        m[freq]++;

        int l_index = i - k + 1;
        ans[l_index] = k - (*m.rbegin()).first;

        auto &freq_remove = f[v[l_index]];
        m[freq_remove]--;
        if (m[freq_remove] == 0)
            m.erase(freq_remove);
        freq_remove--;
        m[freq_remove]++;
    }
    debug(ans);

    for (int qq = 0; qq < q; qq++)
    {
        ll l, r;
        cin >> l >> r;

        cout << ans[l - 1] << '\n';
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