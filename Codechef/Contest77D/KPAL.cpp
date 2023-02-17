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
    map<int, int> a;
    map<int, int> b;
    a.swap(b);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0, k = 0;
        cin >> n >> k;
        int a[100000];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        ll ans = 1;
        for (int i = 0, l = n - 1; i < l; i++, l--)
        {
            if (a[i] != a[l])
            {
                ans = 0;
                break;
            }
        }
        if (ans == 1)
            ans = 1;
        else
        {
            if (k == n)
            {
                ans = 0;
            }
            else if (n % 2 == 0 && k % 2 == 0)
            {
                if (sum % 2 == 0)
                    ans = 1;
            }
            else
                ans = 1;
        }

        cout << ((ans) ? "YES" : "NO")el;
        // cout << ans el;
    }
    return 0;
}