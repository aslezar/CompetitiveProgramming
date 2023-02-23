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
        vector<int> a, b;
        vector<pair<int, int>> c;
        cin >> n >> k;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            c.push_back({a[i] + b[i], a[i]});
        }
        ll ans = 0;
        sort(c.begin(), c.end());

        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (k - ans >= c[i].first)
                ans += c[i].first;
            else
                break;
        }
        for (int j = i; j < n; j++)
        {
            if (k - ans >= c[j].second)
            {
                i++;
                break;
            }
        }
        cout << i el;
    }
    return 0;
}