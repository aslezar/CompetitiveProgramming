#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
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
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> ans(c, 0);
        for (int i = 0; i < c; i++)
        {
            int t1 = a & (1 << i);
            int t2 = b & (1 << i);
            if (t1 == t2)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = 0;
            }
        }
        int final = 1;
        for (auto &&i : ans)
        {
            // cout << i << ' ';
            if (i == 0)
                final = final * 2;
        }
        cout << final << '\n';
    }
    return 0;
}