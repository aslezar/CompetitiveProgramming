#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el << '\n'

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
        ll a[n];
        bool flag = 0;
        ll pve = INT_MAX, nve = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (!a[i])
                flag = 1;
            else if (a[i] > 0 && a[i] < pve)
                pve = a[i];
            else if (a[i] < 0 && a[i] > nve)
                nve = a[i];
        }

        ll ans = 0;
        if (flag)
            ans = 0;
        else
        {
            ans = (pve < (nve * -1)) ? pve : nve * -1;
        }
        // cout<<(()?"yes":"no") el;
        cout << ans - 1 el;
    }
    return 0;
}