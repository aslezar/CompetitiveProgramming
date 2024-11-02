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

int __sum(int l)
{
    return 0;
}

// s included,e not included, 0 index
int range(int seg, int s, int e, vi &vvv, vi &vv)
{
    if (e <= s)
        return 0;
    // debug(vvv[e] - vvv[s] - (vv[seg - 1] * (e - s)));
    return vvv[e] - vvv[s] - (vv[seg - 1] * (e - s));
}
void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n + 1);
    vi vv(n + 1);
    vi vvv(n + 1);
    vi count(n + 1);
    vi diff(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        vv[i] = vv[i - 1] + v[i];
        vvv[i] = vvv[i - 1] + vv[i];
        count[i] = count[i - 1] + n - i + 1;
        diff[i] = diff[i - 1] + v[i] * (n - i + 1);
    }
    debug(v);
    debug(vv);
    debug(vvv);
    debug(count);
    debug(diff);

    vi seg(n + 1);
    int minus = 0;
    for (int i = 1; i <= n; i++)
    {
        // 0 30 56 76 86
        minus += v[i - 1] * (n - i + 2);
        seg[i] = seg[i - 1] + vvv[n] - (minus);
    }
    debug(seg);

    ll q = 0;
    cin >> q;
    for (int qq = 0; qq < q; qq++)
    {
        int l, r;
        cin >> l >> r;

        int s1 = lower_bound(all(count), l) - count.begin();
        int s2 = lower_bound(all(count), r) - count.begin();
        // debug(s1, s2);

        int no1 = l - count[s1 - 1] + s1 - 1;
        int no2 = r - count[s2 - 1] + s2 - 1;
        // debug(no1, no2);

        int sNo1 = s1;
        int sNo2 = s2;
        // debug(sNo1, sNo2);

        int ans = seg[s2] - seg[s1 - 1];
        // debug(ans);

        ans -= range(s1, sNo1 - 1, no1 - 1, vvv, vv);
        ans -= range(s2, no2, n, vvv, vv);

        cout << ans << endl;
    }
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    // cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}