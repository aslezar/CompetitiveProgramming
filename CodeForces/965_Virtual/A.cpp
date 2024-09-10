#include <bits/stdc++.h>
using namespace std;

#define ll long long
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int x = 0, y = 0, k = 0;
        cin >> x >> y >> k;

        for (int i = 0; i < k / 2; i++)
        {
            cout << x + i + 1 << ' ' << y << '\n';
            cout << x - i - 1 << ' ' << y << '\n';
        }
        if (k & 1)
        {
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}