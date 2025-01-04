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
typedef pair<int, int> pii;
constexpr unsigned int mod = 1e9 + 7;

long long val(long long a, long long b, long long c)
{
    return (a ^ b) + (b ^ c) + (c ^ a);
}

auto isBitSet = [](int n, int bit) -> bool
{
    return (n & (1 << bit)) != 0;
};

auto setBit = [](int &n, int bit) -> void
{
    n |= (1 << bit);
};
auto unsetBit = [](int &n, int bit) -> void
{
    n &= ~(1 << bit);
};

void solve([[maybe_unused]] ll &_case_no)
{
    int l, r;
    cin >> l >> r;

    int a = l, b = l, c = r;

    for (int i = 64 - __builtin_clzll(r) - 1; i >= 0; i--)
    {
        int lr = isBitSet(l, i);
        int rr = isBitSet(r, i);
        // debug(i, lr, rr);
        if (lr == rr)
        {
            if (lr)
            {
                int newB = b;
                unsetBit(newB, i);
                // debug(i, newB, b, lr, rr);
                if (newB >= l && newB <= r)
                {
                    b = newB;
                }
            }
            else
            {
                int newB = b;
                setBit(newB, i);
                // debug(i, newB, b, lr, rr);
                if (newB >= l && newB <= r)
                {
                    b = newB;
                }
            }
        }
    }
    debug(val(a, b, c));
    cout << a << ' ' << b << ' ' << c << endl;
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

    debug(val(1, 2, 0));
    debug(val(8, 7, 1));
    debug(val(2, 1, 3));
    debug(val(7, 16, 11));
    debug(val(134, 132, 137));
    debug(val(98, 85, 76));
    debug(val(123, 121, 118));
    debug(val(965321865ll, 375544086ll, 12551794ll));
    return 0;
}