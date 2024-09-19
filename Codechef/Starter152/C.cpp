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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll q = 0;
    cin >> q;
    vi v(n);
    vii cnt(3 + 1, vi(n + 1, 0));
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[1][i + 1] = cnt[1][i];
        cnt[2][i + 1] = cnt[2][i];
        cnt[3][i + 1] = cnt[3][i];
        cnt[v[i]][i + 1]++;
    }
    debug(cnt);

    for (size_t qq = 0; qq < q; qq++)
    {
        ll l, r;
        cin >> l >> r;
        ll len = r - l + 1;
        if (len & 1)
        {
            cout << "No\n";
            continue;
        }
        ll cnt1 = cnt[1][r] - cnt[1][l - 1];
        ll cnt2 = cnt[2][r] - cnt[2][l - 1];
        ll cnt3 = cnt[3][r] - cnt[3][l - 1];
        if (cnt1 == len / 2 || cnt2 == len / 2 || cnt3 == len / 2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
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