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
        vector<int> a;
        for (size_t i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        int z = a[n - 2] + a[n - 1];

        int last = n - 1;
        bool ans = 1;
        for (size_t i = 0; i < n / 2; i++)
        {
            if (a[i] + a[last--] >= z)
            {
                ans = 0;
                break;
            }
        }
        cout << ((ans) ? "Yes" : "No")el;
    }
    return 0;
}