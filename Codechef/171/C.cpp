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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    int p = 0;
    cin >> p;

    vi v(n);
    input(v, n);

    vector<int> ans(n, INT_MAX);
    for (auto &i : v)
    {
        if (i == 0)
            continue;
        i = (i + p - 1) / p;
    }

    int mx = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            mx = 0;
            ans[i] = 0;
        }
        else
        {
            mx = max(mx, v[i]);
            ans[i] = min(ans[i], mx);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == 0)
        {
            mx = 0;
            ans[i] = 0;
        }
        else
        {
            mx = max(mx, v[i]);
            ans[i] = min(ans[i], mx);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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