#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <assert.h>
using namespace std;

#define el << '\n'
#define ws << ' '

typedef long long ll;
typedef long double ld;
const int N = 1e5 + 5, M = 1e9 + 7;

class Fun
{
public:
    // For Mod Mul
    static inline int mul(int a, int b)
    {
        return 1LL * a * b % M;
    }
    // For Mod Power
    static int power(int b, int p)
    {
        if (p == 0)
            return 1;
        int x = power(b, p / 2);
        return p % 2 == 0 ? mul(x, x) : mul(b, mul(x, x));
    }
    // For Inverse Mod
    static int modInvFer(int n)
    {
        return power(n, M - 2);
    }
} fun;

void testcase()
{
    ll n = 0;
    cin >> n;
    assert(n >= 1 && n <= 1e9);

    map<ll, ll> fact;
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
        fact[i] = fun.mul(fact[i - 1], i);

    int a, b;
    map<int, int> x;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x[a]++;
    }
    ll k = 1, den = fact[n];
    for (auto &&i : x)
    {
        k = fun.mul(k, fact[i.second]);
    }
    ans = fun.mul(k, fun.modInvFer(fact[n]));
    cout << ans el;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        testcase();
    return 0;
}