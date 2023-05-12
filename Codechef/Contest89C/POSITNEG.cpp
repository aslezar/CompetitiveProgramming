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
    vector<int> a;
    ll ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t > 0)
        {
            ans += (i + 1);
        }
        else
        {
            ans -= (i + 1);
        }
    }
    if (ans < 0)
        ans *= -1;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        testcase();
    return 0;
}