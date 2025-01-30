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

int nonPalindromicStrs(int n, int k)
{
    if (n <= 1)
        return 0;
    // int ans = (n / 2);
    // ans = (ans * (k - 1)) % mod;
    // ans = (ans * power_mod(k, n - 1)) % mod;
    return (power_mod(k, n) - power_mod(k, (n + 1) / 2) + mod) % mod;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    int k = 0;

    cin >> n;
    cin >> k;

    vi v(n);
    input(v, n);

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ans = (ans * k) % mod;
        }
    }

    int cnt = 0;
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        int &v2 = v[n - i - 1];
        if (v[i] == 0 || v2 == 0)
        {
            if (v[i] == 0 && v2 == 0)
            {
                cnt++;
            }
        }
        else
        {
            if (v[i] != v2)
            {
                cnt = 0;
                possible = false;
                break;
            }
        }
    }
    // 1000000007
    if (possible == true)
    {
        int val = nonPalindromicStrs(cnt, k);
        ans = (ans - val + mod) % mod;
        debug(ans, cnt, possible, val);
    }

    cout << ans << '\n';
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