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
        string a;
        cin >> n >> a;
        ll ans = 0;
        if (n == 1 && a[0] == '0')
            ans = 1;
        else
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (a[i] == '0')
                {
                    if ((a[i + 1] == '+' && a[i - 1] == '-') || (a[i + 1] == '-' && a[i - 1] == '+'))
                        ans++;
                }
            }
            if (a[0] == '0' && a[1] == '0')
                ans++;
            if (a[n - 1] == '0' && a[n - 2] == '0')
                ans++;
        }
        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}