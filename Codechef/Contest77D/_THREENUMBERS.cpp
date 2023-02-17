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
        int a, b, c;
        ll ans = -1;
        cin >> a >> b >> c;
        int no = a, no1 = b, no2 = c;
        if (a % 2 == b % 2 && b % 2 == c % 2)
        {
            int x = a + b + c - min(a, min(b,c));
            x /= 2;
            ans = 3 * x - a - b - c;
        }
        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}