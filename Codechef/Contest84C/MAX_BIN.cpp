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
        ll n = 0, k = 0;
        cin >> n >> k;
        string a;
        cin >> a;
        if (a[0] == '0')
        {
            a[0] = '1';
            k--;
        }
        cout << a;
        for (size_t i = 0; i < k; i++)
            cout << '0';
        cout el;
    }
    return 0;
}