#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
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
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> v(n, 0);
        vector<map<int, int>> f(n);
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            for (size_t i = max(0, a - b - 1); i < a - 1; i++)
            {
                // cout << i ws;
                f[i][a]--;
            }
            // cout el;
            for (size_t i = a; i < min(n, a + b); i++)
            {
                // cout << i ws;
                f[i][a]--;
            }
            // cout el;
        }
        for (size_t i = 0; i < n; i++)
        {
            for (auto &&d : f[i])
            {
                ll temp = 0;
                // temp = (((+d.first - (i + 1)) * (+d.first + 1 - (i + 1))) * d.second);
                // else
                    temp = ((((-d.first + (i + 1)) * (-d.first + 1 + (i + 1)))) * d.second);
                // cout << i << ' ' << d.first << ' ' << d.second << ' ' << temp << '\n';
                v[i] += temp;
            }
        }

        for (auto &&i : v)
            cout << i << ' ';
        cout << '\n';
        // for (size_t i = max(0, a - b - 1); i < a - 1; i++)
        // {
        //     v[i] -= ((a - (i + 1)) * (a - (i + 1) + 1));
        // }
        // for (size_t i = a; i < min(n, a + b); i++)
        // {
        //     v[i] += ((i + 1 - a) * (i + 2 - a));
        // }
        // v[i] -= ((+a - (i + 1)) * (+a + 1 - (i + 1)));
        // v[i] += ((-a + (i + 1)) * (-a + 1 + (i + 1)));
    }
    return 0;
}