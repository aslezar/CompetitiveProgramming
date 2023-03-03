#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>
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
        vector<int> a;
        int temp = 0;
        ll max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            temp = 0;
            cin >> temp;
            max = max < temp ? temp : max;
            a.push_back(temp);
        }
        ll ans = 0;
        sort(a.begin(), a.end());
        ans = a[n - 1] - a[0];
        // for (int i = 0; i < n; i++)
        // {
        //     ans += (max - a[i]);
        // }

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}