#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
ll fn(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 4;
    if (n == 3)
        return 16;
    int bit = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & (pow(2, i)) != 0)
            bit = i;
    }
    return 2 * (fn(n - pow(2, bit)) % mod) + ((long long)(pow(2, 2 * bit)) % mod);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;

        // cout<<(()?"YES":"NO") el;
        cout << fn(n) el;
    }
    return 0;
}