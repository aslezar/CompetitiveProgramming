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
        string ans;
        cin >> ans;
        int size = ans.length();
        if (size > 10)
        {
            cout << ans[0] << size - 2 << ans[size - 1];
        }
        else
            cout << ans el;
        cout el;
    }
    return 0;
}