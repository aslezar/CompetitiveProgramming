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

        vector<string> a, b;
        string temp;

        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        bool flag = 0;
        map<int, int> m;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i].size() != b[i].size())
            {
                flag = 1;
                break;
            }
            for (size_t j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] != b[i][j])
                {
                    m[a[i][j]]++;
                    m[b[i][j]]--;
                }
            }
        }
        if (flag)
        {
            cout << "NO" el;
            continue;
        }
        ll ans = 0;
        for (auto &&i : m)
        {
            if (i.second > 0)
            {
                ans++;
            }
        }

        cout << ((ans <= k) ? "yes" : "no") el;
    }
    return 0;
}