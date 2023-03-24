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
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (2 * j + 1) + 2 * n * i ws;
            cout el;
        }
        if (n & 1)
        {
            for (int i = 0; i < n / 2; i++)
                cout << (n * (n - 1)) + (2 * i + 1) ws;
            cout << n * n ws;
            for (int i = 0; i < n / 2; i++)
                cout << (n * (n - 1)) + (2 * i + 1) + 1 ws;
            cout el;
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (2 * (j + 1)) + (2 * n * i) ws;
            cout el;
        }
    }
    return 0;
}