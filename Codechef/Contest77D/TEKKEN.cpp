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
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        int ans = b - c;
        if (ans < 0)
            ans *= -1;
        if (a > ans)
            ans = 1;
        else
            ans = 0;
        cout << (ans ? "YES" : "NO")el;
        // cout << ans el;
    }
    return 0;
}