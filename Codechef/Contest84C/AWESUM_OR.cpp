#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;
long long power(int b, int e)
{
    long long ans = 1;
    while (e--)
        ans = ((ans * b) % mod);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        int on = 0;
        while (n)
        {
            on += n & 1;
            n >>= 1;
        }
        ll ans = (power(3, on) % mod - ((3LL * power(2, on)) % mod) + 3LL) % mod;
        // ll ans = (((power(3, on) % mod - (3 * (power(2, on) % mod - 1 + mod)) % mod + mod) % mod + mod) % mod);
        // int a = (((mod - 3) * 1ll * power(2, on)) % mod + power(3, on) + 3) % mod;
        cout << ans el;
    }
    return 0;
}