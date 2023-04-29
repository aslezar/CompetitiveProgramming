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

using namespace std;

void help(ll X)
{
    ll a = 1, b = 1, c = X - 1;
    if (c <= 1000000)
    {
        cout << a << ' ' << b << ' ' << c << '\n';
        return;
    }
    for (ll A = 1000000; A > 0; A--)
    {
        ll B = X / A;
        ll C = X - (A * B);
        if (C == 0)
        {
            C = A;
            B = B - 1;
        }
        if (C <= 1000000 && C > 0 && B < 1000000 && B > 0)
        {
            if (A * B + C == X)
            {
                cout << A << ' ' << B << ' ' << C << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
    return;
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
        if (n == 1)
            cout << -1 << '\n';
        else
        {
            help(n);
        }
    }
    return 0;
}