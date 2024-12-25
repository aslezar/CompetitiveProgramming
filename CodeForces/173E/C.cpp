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

int maximumPreSum(vi &v, int i, int j)
{
    int globalMax = v[i];
    int localMax = v[i];
    for (int k = i + 1; k <= j; k++)
    {
        localMax = max(v[k], localMax + v[k]);
        globalMax = max(globalMax, localMax);
    }
    return globalMax;
}

int minimumPreSum(vi &v, int i, int j)
{
    int globalMin = v[i];
    int localMin = v[i];
    for (int k = i + 1; k <= j; k++)
    {
        localMin = min(v[k], localMin + v[k]);
        globalMin = min(globalMin, localMin);
    }
    return globalMin;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    int s = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != -1 && v[i] != 1)
        {
            s = i;
            break;
        }
    }

    if (s == -1)
    {
        int mx = maximumPreSum(v, 0, n - 1);
        int mn = minimumPreSum(v, 0, n - 1);
        if (mn == 1)
        {
            mn = 0;
        }
        else if (mx == -1)
        {
            mx = 0;
        }
        cout << mx - mn + 1 el;
        for (int i = mn; i <= mx; i++)
        {
            cout << i ws;
        }
        cout el;
        return;
    }

    vii intervals;

    vi l = {INT_MAX, INT_MIN};
    if (s != 0)
    {
        int mx = maximumPreSum(v, 0, s - 1);
        int mn = minimumPreSum(v, 0, s - 1);
        intervals.push_back({mn, mx});
        int sum = 0;
        for (int i = s - 1; i >= 0; i--)
        {
            l[0] = min(l[0], sum + v[i]);
            l[1] = max(l[1], sum + v[i]);
            sum += v[i];
        }
        intervals.push_back(l);
        intervals.push_back({min(l[0] + v[s], l[0] + v[s]), max(l[1] + v[s], l[1] + v[s])});
    }

    vi r = {INT_MAX, INT_MIN};
    if (s != n - 1)
    {
        int mx = maximumPreSum(v, s + 1, n - 1);
        int mn = minimumPreSum(v, s + 1, n - 1);
        intervals.push_back({mn, mx});
        int sum = 0;
        for (int i = s + 1; i < n; i++)
        {
            r[0] = min(r[0], sum + v[i]);
            r[1] = max(r[1], sum + v[i]);
            sum += v[i];
        }
        intervals.push_back({min(r[0] + v[s], r[0] + v[s]), max(r[1] + v[s], r[1] + v[s])});
        intervals.push_back(r);
    }

    if (l[0] != INT_MAX && r[1] != INT_MIN)
    {
        if (l[0] + v[s] <= r[1] + v[s])
            intervals.push_back({l[0] + v[s], r[1] + v[s]});
        else
            intervals.push_back({r[1] + v[s], l[0] + v[s]});
        if (l[1] + v[s] <= r[0] + v[s])
            intervals.push_back({l[1] + v[s], r[0] + v[s]});
        else
            intervals.push_back({r[0] + v[s], l[1] + v[s]});
    }

    intervals.push_back({v[s], v[s]});
    intervals.push_back({0, 0});

    sorta(intervals);
    vii merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        auto &last = merged.back();
        auto &current = intervals[i];
        if (current[0] <= last[1])
        {
            last[1] = max(last[1], current[1]);
        }
        else
        {
            merged.push_back(current);
        }
    }

    debug(merged);
    int cnt = 0;
    for (auto &m : merged)
    {
        cnt += m[1] - m[0] + 1;
    }

    cout << cnt el;
    for (auto &m : merged)
    {
        for (int i = m[0]; i <= m[1]; i++)
        {
            cout << i ws;
        }
    }
    cout << '\n';
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