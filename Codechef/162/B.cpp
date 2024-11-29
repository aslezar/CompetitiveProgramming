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
    int n, k;
    cin >> n >> k;

    if (n == 1 || k == 1)
    {
        cout << -1 el;
        return;
    }

    if (n % k == 1 && k == 2)
    {
        cout << -1 el;
        return;
    }

    int shift = 1;
    if (n % k == 1)
        shift = 2;

    vi ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = i + 1;
    }
    reverse(ans.begin(), ans.end());
    reverse(ans.begin(), ans.begin() + shift);
    reverse(ans.begin() + shift, ans.end());

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] ws;
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