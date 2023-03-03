#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0, b = 0;
        cin >> n >> b;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        ans = a[n - b] - 1;

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}