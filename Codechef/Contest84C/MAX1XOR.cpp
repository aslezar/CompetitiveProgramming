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

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        string s;
        cin >> s;
        int prev = 0;
        int count = 0;
        for (size_t i = 0; i < n - 1; i++)
        {
            int cur = prev ^ (s[i] - '0');
            // cout << cur << ' ';
            if (cur == 1)
                count++;
            prev = cur;
        }
        cout << max(n - count, count) el;
    }
    return 0;
}