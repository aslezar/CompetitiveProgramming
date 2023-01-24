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
        ll n = 0, y = 0;
        cin >> n >> y;
        ll ans = 0;
        ll temp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            ans |= temp;
        }
        if (((ans ^ y) | ans) == y)
            ans ^= y;
        else
        {
            ans = -1;
        }
        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}