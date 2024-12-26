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

    int l1 = (l + g - 1) / g, r1 = r / g;

    debug(l1, r1);

    int ans1 = -1, ans2 = -1;
    for (int i = l1; i <= min(r1, l1 + 18); i++)
    {
        for (int j = r1; j >= max(i, r1 -18); j--)
        {
            if (__gcd(i, j) == 1)
            {
                if (ans1 == -1 || abs(j - i) > abs(ans2 - ans1))
                {
                    debug(ans1, ans2);
                    debug(i, j);
                    ans1 = i;
                    ans2 = j;
                }
            }
        }
    }
    if (ans1 == -1)
        g = 1;
    cout << ans1 * g << ' ' << ans2 * g << endl;
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