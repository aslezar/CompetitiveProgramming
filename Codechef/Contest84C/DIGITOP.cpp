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

        map<char, int> replace;
        bool flag = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i].size() != b[i].size())
            {
                flag = 1;
                break;
            }
            vector<int> extra;
            for (size_t j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] != b[i][j])
                {
                    if (replace[b[i][j]].second != i + 1)
                    {
                        replace[a[i][j]].first++;
                        replace[b[i][j]].first--;
                    }
                    else
                    {
                        replace
                    }
                }
            }
        }
        if (flag)
        {
            cout << "no" el;
            continue;
        }
        ll ans = 0;
        for (auto &&i : no)
        {
            if (i.second != 0)
                ans++;
        }
        cout << ans;
        cout << ((ans <= k) ? "yes" : "no") el;
    }
    return 0;
}