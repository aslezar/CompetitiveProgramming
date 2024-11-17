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
constexpr unsigned int mod = 998244353;

unordered_map<int, int> dp;
int power(int bits)
{
    if (dp.count(bits))
        return dp[bits];
    return dp[bits] = ((int)pow(10, bits) % mod);
}

int a[mod];
void precompute()
{
    dp=unordered_map<int, int>();
    int no = 0;
    for (int i = 1; i < mod; i++)
    {
        int n = 0;
        for (int j = __builtin_clz(i); j < 32; j++)
        {
            n *= 10;
            int x = (i & (1 << (32 - j - 1)));
            if (x)
                n += 1;
            else
                n += 0;
        }
        int bits = 32 - __builtin_clz(i);
        no = ((no % mod) * (power(bits) % mod)) % mod + (n % mod);
        a[i] = no;
    }
    for (int i = 1; i < 10; i++)
    {
        debug(a[i]);
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    if (n >= mod)
    {
        cout << 0 el;
        return;
    }
    cout << a[n] el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    precompute();
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}