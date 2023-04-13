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
        ll ans = 0;
        if (n == 1)
            ans = 0;
        else if (n == 2)
            ans = 0;
        else if (n == 3)
            ans = 2;
        else if (n == 4)
            ans = 3;
        else if (n == 5)
            ans = 5;
        else
        {
            ans = 2;
            n -= 3;
            n++;
            ans += (n / 2) * 3;
            if (n % 2 == 0)
                ans -= 2;
        }
        cout << ans el;
    }
    return 0;
}