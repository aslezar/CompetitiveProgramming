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
        int n = 0, q = 0;
        cin >> n >> q;
        vector<int> sum;
        sum.push_back(0);
        int temp = 0;
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            sum.push_back(sum[i] + temp);
        }
        int a = 0, b = 0, c = 0;
        while (q--)
        {
            cin >> a >> b >> c;
            int tempsum = sum[n] + ((b - a + 1) * c) - sum[b] + sum[a - 1];
            cout << ((tempsum & 1) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}