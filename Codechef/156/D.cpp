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

    vi v(n);
    input(v, n);

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = max(0ll, i - 100); k <= min(n - 1, i + 100); k++)
        {
            int val = abs(v[i] - v[k]);
            int iVal = abs(i - k);
            if (val < iVal)
            {
                continue;
            }
            else if (val == iVal)
            {
                ans += (iVal + 1);
            }
            else
            {
                int d = val - iVal;
                if (d & 1)
                    continue;
                d /= 2;
                int p1 = min(i, k) - d;
                int p2 = max(i, k) + d;
                if (p1 >= 0 && p1 < n)
                {
                    ans++;
                }
                if (p2 >= 0 && p2 < n)
                {
                    ans++;
                }
                // if (val <= abs(0 - i) + abs(0 - k))
                //     ans++;
                // if (val <= abs(n - 1 - i) + abs(n - 1 - k))
                //     ans++;
            }
        }
    }
    cout << ans el;
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