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
        int odd = 0, even = 0;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp & 1)
                odd++;
            else
                even++;
        }
        ll ans = 1;
        if (odd & 1)
        {
            ans = 0;
        }

        cout << ((ans) ? "YES" : "NO")el;
    }
    return 0;
}