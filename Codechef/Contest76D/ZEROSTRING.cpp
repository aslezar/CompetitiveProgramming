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
        string c;
        cin >> c;
        ll noof1 = count(c.begin(), c.end(), '1');
        ll noof0 = n - noof1;
        ll ans = noof1;
        if (noof1 > noof0)
            ans = noof0 + 1;
        else
            ans = noof1;

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}