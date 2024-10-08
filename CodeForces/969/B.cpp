#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount
#define gcd __gcd

constexpr unsigned int mod = 1e9 + 7;
constexpr ll maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

void solve([[maybe_unused]] ll &_case_no)
{
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    ll mx = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    for (int i = 0; i < m; i++)
    {
        char o;
        ll l, r;
        cin >> o >> l >> r;
        if (mx >= l && mx <= r)
        {
            if (o == '+')
            {
                mx++;
            }
            else if (o == '-')
            {
                mx--;
            }
        }
        cout << mx << ' ';
    }
    cout << endl;
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