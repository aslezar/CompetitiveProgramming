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
        ll n = 0, x = 0;
        cin >> n >> x;
        bool isoddpresent = 0;
        int noofeven = 0;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
                noofeven++;
            else
                isoddpresent = 1;
        }
        ll ans = -1;
        if (x % 2 == 1)
            ans = (noofeven + 1) / 2;
        else if (isoddpresent)
            ans = noofeven;
        cout << ans el;
    }
    return 0;
}