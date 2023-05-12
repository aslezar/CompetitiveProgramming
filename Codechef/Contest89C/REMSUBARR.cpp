#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
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

bool inline btw(int a, int b, int m)
{
    int l = min(a, b);
    int r = max(a, b);
    if (m > l && m < r)
        return true;
    return false;
}
void testcase()
{
    ll n = 0;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;
        m[t] = i;
    }
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    int mini = n, maxi = 0;
    int len = 1;
    for (int i = n; i > 1; i--)
    {
        mini = min(mini, m[i]);
        maxi = max(maxi, m[i]);
        if (maxi - mini == (n - i))
            len = maxi - mini + 1;
    }
    cout << len << '\n';
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