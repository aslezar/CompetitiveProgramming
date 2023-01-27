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
        string no;
        cin >> no;
        bool ans = 1;
        int cnt = count(no.begin(), no.end(), '1');
        if (cnt >= 4)
            ans = 0;
        else if (cnt == 1 && n < 3)
        {
            ans = 0;
        }
        cout << ((ans) ? "YES" : "NO")el;
        // cout << ans el;
    }
    return 0;
}