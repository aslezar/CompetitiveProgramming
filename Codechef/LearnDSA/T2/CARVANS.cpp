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
ll input(ll a = 0)
{
    cin >> a;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll ans = 0;
        ll maxspeed = input();
        for (int i = 1; i < n; i++)
        {
            int curspeed = 0;
            cin >> curspeed;
            if (curspeed <= maxspeed)
            {
                ans++;
                maxspeed = curspeed;
            }
        }
        // cout<<(()?"YES":"NO") el;
        cout << ans + 1 el;
    }
    return 0;
}