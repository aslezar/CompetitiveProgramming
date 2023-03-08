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
        int temp = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
        }
        ll t1 = m[1];
        ll ans = m[1];
        for (int i = 2; i < 1e9 + 1; i++)
        {
            // cout << i ws << m[i] el;
            if (m[i] == 0)
                break;
            t1 = (t1 * m[i]) % mod;
            ans = (ans + t1 % mod) % mod;
        }
        cout << ans el;
    }
    return 0;
}