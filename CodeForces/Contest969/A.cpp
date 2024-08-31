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
    ll a, b;
    cin >> a >> b;

    set<ll> s;
    ll ans = 0;
    for (ll i = a; i <= b; i++)
    {
        if (i % 2 == 0)
            continue;
        bool found = false;
        if (s.count(i))
        {
            continue;
        }
        for (ll j = b; j >= i + 1; j--)
        {
            if (j % 2 == 0)
                continue;
            if (s.count(j))
            {
                continue;
            }
            if (gcd(i, j) == 1)
            {
                // debug(i, j, k);
                s.insert(i);
                s.insert(j);
                ans++;
                found = true;
                break;
            }
            if (found)
            {
                break;
            }
        }
    }
    ll noOfEvenNumbers = 0;
    for (ll i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            noOfEvenNumbers++;
        }
    }
    cout << min(noOfEvenNumbers, ans) << endl;
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