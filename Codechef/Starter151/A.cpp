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
#define set_bits __builtin_popcount

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    string s;
    cin >> s;
    // debug(s);
    int cnt0 = 0;
    for (auto &i : s)
    {
        if (i == '0')
            cnt0++;
    }
    int ans = 0;
    int cnt1 = n - cnt0;
    // debug(cnt0, cnt1);
    for (int k = 1; k <= n; k++)
    {
        if ((k - cnt0 >= 0) && (k - cnt0) % 2 == 0)
        {
            debug(k);
            ans++;
        }
        else if ((k - cnt1 >= 0) && (k - cnt1) % 2 == 0)
        {
            debug(k);
            ans++;
        }
    }
    cout << ans << endl;
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