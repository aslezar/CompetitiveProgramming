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
    cin.get();
    while (t--)
    {
        int ans = 0;
        char c1 = '0', c2 = '0';
        char temp = '0';
        while (1)
        {
            c1 = c2;
            c2 = temp;
            temp = cin.get();
            if (temp < '0' || temp > '9')
                break;
        }
        if (c1 != '0')
            ans = (int(c1 - '0') % 2) * 10 + (c2 - '0');
        else
            ans = (c2 - '0');
        cout << ans el;
    }
    return 0;
}