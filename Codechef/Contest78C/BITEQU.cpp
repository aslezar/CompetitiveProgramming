#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll ans = n + 1;
        ll a = 8589934592LL, b = 17179869184LL, c = 1;
        if (n == 1)
        {
            a = 1;
            b = 4;
            c = 3;
            ans = 2;
        }
        else if (n == 0)
        {
            a = 15;
            b = 3;
            c = 4;
            ans = 7;
        }
        else if (n == 2)
        {
            a = 2;
            b = 4;
            c = 3;
            ans = 1;
        }
        else
        {
            if (n & 1)
                ans = n - 1;
        }
        cout << (((a & b) | c) ^ ans) el;
        cout << a ws << b ws << c ws << ans el;
    }
    return 0;
}