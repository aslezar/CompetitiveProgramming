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
        int n = 0;
        string str;
        cin >> n >> str;

        bool ans = 1, flag = 1;
        vector<int> v(26, -1);
        char temp;
        for (size_t i = 0; i < n; i++)
        {
            temp = str[i];
            if (v[temp - 'a'] != -1)
            {
                if (v[temp - 'a'] == flag)
                {
                    ans = 0;
                    break;
                }
            }
            else
                v[temp - 'a'] = !flag;
            flag = !flag;
        }

        cout << ((ans) ? "YES" : "NO")el;
    }
    return 0;
}