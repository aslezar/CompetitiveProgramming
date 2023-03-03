#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>
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
        ll a = 0, b = 0;
        cin >> a >> b;
        if (a % 2 == 0)
        {
            cout << (b - a + 1) / 2 el;
        }
        else
        {
            int factor = 2;
            for (; factor < INT_MAX; factor++)
            {
                if (a % factor == 0)
                    break;
            }
            cout << (b - a - factor + 1) / 2 + 1 el;
        }
    }
    return 0;
}