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
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);
    if (n == 1)
    {
        cout << 0 el;
        return;
    }
    sorta(v);
    // debug(v);

    vector<pair<int, int>> intervals;

    for (int i = 0; i < n - 1; i++)
    {
        intervals.push_back({abs(v[i] - v[i + 1]) + 1, v[i] + v[i + 1] - 1});
    }

    // merge intervals
    sorta(intervals);
    // debug(intervals);
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].first <= merged.back().second)
        {
            merged.back().second = max(merged.back().second, intervals[i].second);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }
    // debug(merged);

    int ans = 0;
    for (int i = 0; i < merged.size(); i++)
    {
        ans += merged[i].second - merged[i].first + 1;
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