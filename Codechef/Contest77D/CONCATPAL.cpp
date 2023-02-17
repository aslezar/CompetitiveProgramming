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
        int m = 0, n = 0;
        cin >> n >> m;
        char temp;
        map<int, int> a;
        map<int, int> b;
        bool ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a[temp]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            b[temp]++;
        }
        int odd = 0;
        map<int, int> *ar = &a;
        map<int, int> *br = &b;
        int diff = n - m;
        if (n < m)
        {
            ar = &b;
            br = &a;
            diff *= -1;
        }
        for (int i = 'a'; i <= 'z'; i++)
        {
            (*ar)[i] -= (*br)[i];
            if ((*ar)[i] < 0)
            {
                odd = 2;
                break;
            }
            if ((*ar)[i] % 2)
                odd++;
            // cout << (*ar)[i] ws;
        }
        // cout el;
        // for (int i = 'a'; i < 'z'; i++)
        // {
        //     cout << (*br)[i] ws;
        // }
        if (diff % 2 == odd)
            ans = 1;
        // cout el << diff ws << noofodd ws << ans ws;

        cout << ((ans) ? "YES" : "NO")el;
    }
    return 0;
}