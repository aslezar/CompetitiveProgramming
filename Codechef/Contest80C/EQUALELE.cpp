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
        ll n = 0;
        cin >> n;
        int temp = 0;
        map<int, int, greater<int>> m;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
        }
        int max = INT_MIN;
        for (auto &&i : m)
        {
            if (max < i.second)
                max = i.second;
        }

        ll ans = n - max;
        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}