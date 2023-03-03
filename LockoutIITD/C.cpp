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
        if (n % 2 == 0)
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (i % 2 == 0)
                    cout << i - 1 ws;
                else
                    cout << i + 1 ws;
            }
            cout << n ws << n - 1 el;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (i % 2 == 0)
                    cout << i - 1 ws;
                else
                    cout << i + 1 ws;
            }
            cout << n el;
        }
    }
    return 0;
}