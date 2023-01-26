#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
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
        ll n = 0, k = 0, s = 0;
        cin >> n >> k >> s;
        bool flag = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < n && s > 0; i++)
        {
            if (s % k == 1)
            {
                ans[i] = 1;
            }
            else if (s % k == k - 1)
            {
                ans[i] = -1;
                s++;
            }
            else if (s % k != 0)
            {
                flag = 1;
                break;
            }
            s /= k;
        }
        // cout << t el;
        if (!flag)
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] ws;
            }
            cout el;
        }
        else
            cout << -2 el;
    }
    return 0;
}