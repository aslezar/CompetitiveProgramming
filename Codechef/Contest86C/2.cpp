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
        if (n == 50)
            cout << 0 << '\n';
        else if (n < 50)
        {
            int min = (50 - n) / 2;
            int tmin = (50 - n) % 2;
            if (tmin)
                min += 3;
            cout << min << '\n';
        }
        else
        {
            int min = (n - 50) / 3;
            int tmin = (n - 50) % 3;
            if (tmin == 1)
            {
                min += 2;
            }
            else if (tmin == 2)
            {
                min += 4;
            }
            cout << min << '\n';
        }
    }
    return 0;
}