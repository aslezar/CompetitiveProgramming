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
    int l, r, g;
    cin >> l >> r >> g;

    int rr = r;

    int ans1 = -1, ans2 = -1;
    for (int i = l; i <= rr; i++)
    {
        if (i % g == 0)
        {
            if (rr < g)
                break;
            int x = (rr - g) / i;
            int v = g + (i * x);
            if (v >= l && v <= r && __gcd(i, v) == g)
            {
                if (ans1 == -1 || ans2 - ans1 < v - i)
                {
                    ans1 = i;
                    ans2 = v;
                    rr = v;
                }
            }
        }
    }
    cout << ans1 << ' ' << ans2 el;
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