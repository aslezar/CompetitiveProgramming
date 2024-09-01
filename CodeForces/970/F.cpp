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

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

long long power_mod(long long base, long long exp, long long mod = 1e9 + 7)
{
    // this function multiplies a number by itself n times in O(logn)
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
    vi v(n);
    input(v, n);

    ll p = 0;

    ll sum = v[n - 1] % mod;

    for (int i = n - 2; i >= 0; i--)
    {
        debug(p, sum);
        p = (p + ((v[i] * sum) % mod)) % mod;
        sum = (sum + v[i]) % mod;
    }

    ll q = (n * (n - 1) / 2) % mod;

    ll qi = power_mod(q, mod - 2, mod);
    debug(qi);

    cout << (p * qi) % mod << endl;
    // cout << q << endl;
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