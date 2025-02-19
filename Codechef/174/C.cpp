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
typedef pair<int, int> pii;
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    int mx = *max_element(all(v));
    map<int, int> cnt;
    for (auto &i : v)
    {
        cnt[i]++;
    }

    int ans = mx + cnt[mx];
    for (int g = max(1ll, mx - n + 1); g <= mx; g++)
    {
        int cur = 0;
        for (int i = 1; i * g <= mx; i++)
        {
            cur += cnt[g * i];
        }
        ans = max(ans, g + cur);
    }

    cout << ans << '\n';

    // int g = 0;
    // for (auto &i : v)
    // {
    //     g = gcd(g, i);
    // }

    // unordered_map<int, int> ans;

    // for (auto &j : cnt)
    // {
    //     auto &no = j.first;

    //     for (int i = 1; i * i <= no; i++)
    //     {
    //         if (no % i == 0)
    //         {
    //             int i1 = i;
    //             int i2 = no / i;
    //             debug(no, i1, i2);
    //             if (i1 != no)
    //             {
    //                 ans[no] = max(ans[no], ans[i1] + cnt[no]);
    //             }
    //             if (i2 != no)
    //             {
    //                 ans[no] = max(ans[no], ans[i2] + cnt[no]);
    //             }
    //         }
    //     }
    //     ans[no] = max(ans[no], cnt[no] + no);
    // }
    // debug(ans);
    // int final = n + g;
    // for (auto &i : ans)
    // {
    //     final = max(final, i.second);
    // }
    // cout << final << '\n';
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