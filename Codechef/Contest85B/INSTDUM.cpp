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
        vector<int> v;
        int run = 0;
        int ans = 0;
        for (size_t balls = 1; balls <= n; balls++)
        {
            int temp = 0;
            cin >> temp;
            run += temp;
            if (run == balls)
                ans++;
        }
        cout << ans el;
    }
    return 0;
}