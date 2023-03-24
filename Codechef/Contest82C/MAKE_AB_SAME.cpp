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
        vector<bool> a, b;
        int temp = 0;
        bool is1 = false;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
            if (temp == 1)
                is1 = true;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        if (a[0] != b[0] || a[n - 1] != b[n - 1])
        {
            cout << "NO\n";
            continue;
        }
        ll ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1 && b[i] == 0)
            {
                ans = 0;
                break;
            }
            if (a[i] == 0 && b[i] == 1)
            {
                if (is1 == false)
                {
                    ans = 0;
                    break;
                }
            }
        }
        cout << ((ans) ? "YES" : "NO")el;
    }
    return 0;
}