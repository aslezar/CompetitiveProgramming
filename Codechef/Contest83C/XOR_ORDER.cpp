#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
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
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (a < b && b < c)
        {
            cout << 0 el;
            continue;
        } // else if (a > b && b > c)
        //     cout << a el;
        // else
        //     cout << -1 el;
        int d = a ^ c;
        int k = 30;
        while (k >= 0 && !((d >> k) & 1))
        {
            k--;
        }
        if (k < 0)
        {
            cout << -1 el;
            continue;
        }
        int x = (1 << (k + 1)) - 1;
        if ((a ^ x) < (b ^ x) && (b ^ x) < (c ^ x))
        {
            cout << x el;
        }
        else
        {
            cout << -1 el;
        }
    }
    return 0;
}