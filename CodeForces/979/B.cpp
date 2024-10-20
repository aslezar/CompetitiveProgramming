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

long long power_mod(long long base, long long exp, long long mod = 1e9 + 7)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    int no_of_zero = 0;
    int maxValue = INT_MAX;
    int t = power_mod(2, n) + 1;
    for (int i = 1; i <= n; i++)
    {
        int cur = abs(power_mod(2, i + 1) - t);
        // no_of_zero = min(no_of_zero, cur);
        if (cur < maxValue)
        {
            maxValue = cur;
            no_of_zero = i;
        }
    }
    for (int i = 0; i < no_of_zero; i++)
    {
        cout << 0;
    }
    for (int i = no_of_zero; i < n; i++)
    {
        cout << 1;
    }
    cout el;
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