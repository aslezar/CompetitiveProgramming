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

vi fact(1e7, 1);
void factCalc()
{
    for (int i = 1; i < 1e7; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
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

long long nCr(long long a, ll b)
{
    long long ans = fact[a + b];
    ans = (ans * power_mod(fact[a], mod - 2, mod)) % mod;
    ans = (ans * power_mod(fact[b], mod - 2, mod)) % mod;
    return ans;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll total0, total1;
    cin >> total0 >> total1;

    ll half_sum = (total0 + total1) / 2;
    int A = (half_sum + 1) / 2;
    int B = half_sum / 2;

    ll ans = 0;

    for (int i = 0; i <= B; i++)
    {
        if (A - i < 0 || B - i < 0 || total1 - 2 * i < 0 || half_sum - (total1 - 2 * i) < 0)
            continue;
        int curArr = ((nCr(i, A - i) * nCr(i, B - i)) % mod) * nCr(total1 - 2 * i, half_sum - (total1 - 2 * i)) % mod;

        ans = (ans + curArr) % mod;
    }

    cout << ans el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    factCalc();
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}