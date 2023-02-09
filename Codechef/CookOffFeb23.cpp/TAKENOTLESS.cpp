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
        string ans = "Zenyk";
        map<int, int, greater<int>> m;
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            cin >> a;
            m[a]++;
        }
        auto it = m.begin();
        while (it != m.end())
        {
            if (it->second % 2 == 1)
            {
                ans = "Marichka";
                break;
            }
            it++;
        }

        cout << ans el;
    }
    return 0;
}