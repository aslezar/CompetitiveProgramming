#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll b, c, d;
    cin >> b >> c >> d;

    ll a = 0;

    // iterate over each bit
    for (int i = 0; i < 64; i++)
    {
        bool bit_b = (b >> i) & 1;
        bool bit_c = (c >> i) & 1;
        bool bit_d = (d >> i) & 1;
        if (bit_b == 0 && bit_c == 1 && bit_d == 1)
        {
            debug(i, bit_b, bit_c);
            cout << -1 el;
            return;
        }
        if (bit_b == 1 && bit_c == 0 && bit_d == 0)
        {
            debug(i, bit_b, bit_c);
            cout << -1 el;
            return;
        }
        // set ith bit of a
        a = a | (1LL << i);
        if (bit_b == 1 && bit_c == 1 && bit_d == 1)
        {
            // flip the bit
            a = a & ~(1LL << i);
        }
        if (bit_b == 0 && bit_c == 0 && bit_d == 0)
        {
            // flip the bit
            a = a & ~(1LL << i);
        }
    }

    cout << a el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}