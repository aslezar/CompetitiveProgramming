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
        ll k = 0;
        int a = 0, b = 0;
        cin >> k >> a >> b;
        int sum = a + b;
        ll ans = sum;

        // ll s = (2 * sum) % 10 + (4 * sum) % 10 + (8 * sum) % 10 + (6 * sum) % 10;
        if (k == 2)
        {
            cout << ((ans % 3) == 0 ? "YES" : "NO") el;
            continue;
        }
        ans += sum % 10;
        k -= 3;
        ans += (2 * sum % 10) * (k / 4);
        ans += (4 * sum % 10) * (k / 4);
        ans += (6 * sum % 10) * (k / 4);
        ans += (8 * sum % 10) * (k / 4);
        k %= 4;
        int mul = 2;
        while (k--)
        {
            ans += ((mul * sum) % 10);
            mul = (mul * 2) % 10;
        }

        cout << ((ans % 3) == 0 ? "YES" : "NO") el;
        // cout << ans el;
    }
    return 0;
}