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
        int no = n % 10;
        if (no >= 5)
        {
            n = n + (10 - no);
        }
        else
        {
            n = n - no;
        }

        // cout<<(()?"YES":"NO") el;
        cout << 100 - n el;
    }
    return 0;
}