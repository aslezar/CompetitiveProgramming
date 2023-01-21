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
        ll a = 0, b=0;
        cin >> a>>b;

        cout<<((3*a<=b)?"yes":"no") el;
        // cout << ans el;
    }
    return 0;
}