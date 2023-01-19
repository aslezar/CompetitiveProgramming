#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el << '\n'

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
        ll a[n], b[n];
        int max = 0;
        bool flag = 0;
        vector<int> index;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == a[max] && i != max)
            {
                flag = 1;
                index.push_back(i);
            }
            else if (a[i] > a[max])
            {
                max = i;
                if (flag)
                    index.clear();
                flag = 0;
            }
        }

        for (int i = 0; i < n; i++)
            cin >> b[i];

        ll ans = max;
        if (flag)
            for (int i : index)
                if (b[ans] < b[i])
                    ans = i;
        // cout<<(()?"yes":"no") el;
        cout << ans + 1 el;
    }
    return 0;
}