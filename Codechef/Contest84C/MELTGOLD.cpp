#include <iostream>
#include <vector>
#include <set>
#include <math.h>
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
        ll a = 0, b = 0;
        cin >> a >> b;
        a -= b;
        int i = 1;
        for (; i < 1000000; i++)
        {
            a -= i;
            if (a <= 0)
                break;
        }
        cout << i el;
    }
    return 0;
}