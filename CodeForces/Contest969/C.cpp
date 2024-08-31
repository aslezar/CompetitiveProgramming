#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
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
    ll n, a, b;
    cin >> n >> a >> b;

    ll g = gcd(a, b);

    vector<ll> s(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] %= g;
    }
    sorta(s);

    ll ans = s[n - 1] - s[0];

    for (int i = 1; i < n; i++)
    {
        ll temp = (s[(i - 1 + n) % n] + g) - s[i];
        ans = min(ans, temp);
    }

    cout << ans << endl;
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