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
        int ans = -1;

        int temp = 0;
        map<int, int> m;
        vector<int> a;

        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
            a.push_back(temp);
            if (m[temp] == 3)
                ans = 0;
        }
        if (ans != 0)
        {
            ans = INT_MAX;
            sort(a.begin(), a.end());
            for (int i = 0; i < n - 2; i++)
            {
                if (i != 0 && a[i] == a[i - 1])
                    continue;
                for (int j = n - 1; j >= i + 2; j--)
                {
                    if (j != n - 1 && a[j] == a[j + 1])
                        continue;
                    int temp = (a[i] + a[j]) / 2;
                    for (int k = i + 1; k < j; k++)
                    {
                        ans = min(ans, abs(temp - 2 * a[k]));
                        if (ans == 0)
                            break;
                    }
                }
                if (ans == 0)
                    break;
            }
        }

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}