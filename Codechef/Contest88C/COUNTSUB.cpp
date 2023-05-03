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
        map<int, int> m;
        for (size_t i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            m[temp]++;
        }
        int ans = (n * (n - 1)) / 2;
        for (auto &&i : m)
        {
            int temp = (i.second * (i.second - 1)) / 2;
            ans = ans - temp;
        }
        cout << ans el;
    }
    return 0;
}