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
        int n = 0;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            for (int i = n; i > (n - (n / 2)); i--)
            {
                cout << i << ' ';
            }
            for (int i = 1; i <= ((n + 1) / 2); i++)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}