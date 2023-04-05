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
        ll n = 0, a = 0;
        cin >> n >> a;
        ll ans = 0;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp >= a)
                ans++;
        }

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}