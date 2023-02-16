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
        if (a == b)
        {
            no = c;
            no1 = a;
            no2 = b;
        }
        else if (b == c)
        {
            no = a;
            no1 = b;
            no2 = c;
        }
        else if (a == c)
        {
            no = b;
            no1 = a;
            no2 = c;
        }
        if (no1 == no2 && (no - no1) % 2 == 0)
            ans = (no - no1) / 2;
        cout << ans el;
    }
    return 0;
}