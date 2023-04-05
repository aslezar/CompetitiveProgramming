#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int power(int a, int b)
{
    int ans;
    for (size_t i = 0; i < a; i++)
    {
        ans = (ans * b) % mod;
    }
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
        int ans = 0;
        int on = (int)log2(n) + 1;
        if (on < 3)
        {
            cout << 0 el;
        }
        else
        {
            for (int i = 1; i <= n - 3; i++)
                ans = (ans * i) % mod; // compute (n-3)!

            ans = (ans * (power(2, n) - 2)) % mod; // multiply by (2^n - 2)
            cout << ans;
        }
    }
    return 0;
}