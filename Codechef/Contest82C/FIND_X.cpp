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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = 0;
        if (((a + 1) % b) == ((c + 1) % d))
        {
            cout << 1 el;
            continue;
        }
        if (b > d)
        {
            swap(a, c);
            swap(b, d);
        }
        ans = b * d / __gcd(b, d) - (a % b);
        cout << ans el;
    }
    return 0;
}