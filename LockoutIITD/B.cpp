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
    ll n = 0, a = 0, b = 0;
    cin >> n >> a >> b;
    for (int k = 2; k <= n - 1; k++)
    {
        ll ans = 0;
        if (k % 2 == 1 && a != b)
            ans = 1;
        cout << ((ans) ? "YES" : "NO")el;
    }
    return 0;
}