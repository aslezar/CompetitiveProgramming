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

int helper(vi v, int n)
{
    sorta(v);
    vi s;
    for (int i = 0; i < n; i += 2)
    {
        s.push_back(v[i + 1] - v[i]);
    }
    return *max_element(all(s));
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    if (n == 1)
    {
        cout << 1 el;
        return;
    }

    if (n % 2 == 0)
    {
        int ans = helper(v, n);
        cout << ans el;
        return;
    }

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        v.push_back(v[i]);
        ans = min(ans, helper(v, n));
        v.pop_back();
    }
    cout << ans el;
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