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
    ll k = 0;
    cin >> k;

    ll n = LLONG_MAX;

    int l = 1, r = LLONG_MAX;
    // double max value
    double d = LLONG_MAX;

    debug(sqrt(ll(1e18)));
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        // sq root
        ll t = m - floor(sqrt(m));
        if (t == k)
        {
            n = min(n, m);
        }
        if (t < k)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << n el;
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