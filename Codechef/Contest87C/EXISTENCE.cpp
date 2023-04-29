#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned long long mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        unsigned ll x = 0, y = 0;
        cin >> x >> y;
        ll t1 = x * x;
        if (t1 == (2 * y))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}