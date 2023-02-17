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
        string a;
        cin >> n >> a;
        ll ans = 0;
        bool flag = 0;
        char lastchar = '\0';
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (flag)
            {
                if (a[i] == '0')
                {
                    cnt++;
                }
                else if (a[i] == lastchar)
                {
                    cnt = 0;
                }
                else
                {
                    if (cnt % 2 && cnt != 0)
                        ans++;
                    cnt = 0;
                    lastchar = a[i];
                }
            }
            else
            {
                if (a[i] != '0')
                {
                    lastchar = a[i];
                    flag = 1;
                }
            }
        }
        if (!flag)
            ans = n;
        cout << ans el;
    }
    return 0;
}