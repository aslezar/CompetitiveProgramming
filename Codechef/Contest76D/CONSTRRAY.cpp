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
        ll n = 0;
        cin >> n;
        ll ans = 0;
        if (n % 2 == 1)
        {
            cout << -1 el;
            continue;
        }
        int a = 2;
        for (int i = 0; i < n / 2; i++)
        {
            cout << a ws;
            if (a < 0)
            {
                a *= -1;
                a++;
            }
            else
            {
                a++;
                a *= -1;
            }
        }
        a--;
        for (int i = 0; i < n / 2; i++)
        {
            cout << a ws;
            if (a > 0)
            {
                a *= -1;
                a++;
            }
            else
            {
                a++;
                a *= -1;
            }
        }
        cout el;
    }
    return 0;
}