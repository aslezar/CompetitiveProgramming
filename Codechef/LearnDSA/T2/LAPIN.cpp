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
        string n;
        cin >> n;
        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0, j = n.size() - 1; i < n.size() / 2; i++, j--)
        {
            m1[n[i]]++;
            m2[n[j]]++;
        }
        bool ans = 1;
        for (int i = 0; i < 26; i++)
        {
            if (m1[i + 'a'] != m2[i + 'a'])
            {
                ans = 0;
                break;
            }
        }

        cout << ((ans) ? "YES" : "NO")el;
        // cout << ans el;
    }
    return 0;
}