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

constexpr unsigned int mod = 998244353;

// mofulao factorial of n
ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans = (ans * i) % mod;
    }
    return ans % mod;
}

long long power_mod(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    vi v((2 * n));
    input(v, (2 * n));
    ll g1 = 0, g2 = 0;
    ll pairs = 0;

    ll gadbad1 = 0, gadbad2 = 0;

    unordered_set<ll> s1,s2;

    for (size_t i = 0; i < n; i++)
    {
        ll index = 2 * i;
        ll index2 = 2 * i + 1;
        if (v[index] == 0 && v[index2] == 0)
        {
            pairs++;
        }
        else if (v[index] != 0 && v[index2] != 0)
        {
            if (v[index] <= n && v[index2] <= n)
            {
                gadbad1++;
            }
            else if (v[index] > n && v[index2] > n)
            {
                gadbad2++;
            }
        }
        if(v[index]>=1 && v[index]<=n)
        {
            s1.insert(v[index]);
        }
        if(v[index2]>=1 && v[index2]<=n)
        {
            s1.insert(v[index]);
        }
        

    }
    g1 = n - g1;
    g2 = n - g2;
    debug(g1, g2, pairs, gadbad1, gadbad2);

    if (gadbad1 <= gadbad2)
    {
        ll cnt = gadbad2 - gadbad1;
        ll notInP = 0;
        // n n-1 ... n-cnt+1

        for (size_t i = n; i >= n - cnt + 1; i++)
        {
            // search in v if i is present using stl
            if (find(v.begin(), v.end(), i) == v.end())
            {
                notInP++;
            }
        }

        g2 += notInP;
        g1 -= notInP;
    }
    else
    {
        ll cnt = gadbad1 - gadbad2;
        ll notInP = 0;
        // n+1 n+2 ... n+cnt
        for (int i = n + 1; i <= n + cnt; i++)
        {
            if (find(v.begin(), v.end(), i) == v.end())
            {
                notInP++;
            }
        }
        g1 += notInP;
        g2 -= notInP;
    }

    assert(g1 >= 0);
    assert(g2 >= 0);
    debug(g1, g2, pairs);
    // // ans = g1! *g2! *(2 ^ pairs)
    ll fact1 = fact(g1);
    ll fact2 = fact(g2);
    ll ans = (fact1 * fact2) % mod;

    ll power = power_mod(2, pairs);
    ans = (ans * power) % mod;
    debug(fact1, fact2, power);
    cout << ans << '\n';
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