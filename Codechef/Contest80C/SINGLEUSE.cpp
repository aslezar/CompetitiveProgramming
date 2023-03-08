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
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        a -= c;
        ll ans = 1;
        ans += (a + b - 1) / b;

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}