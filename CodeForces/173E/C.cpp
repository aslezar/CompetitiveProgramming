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

vi maxmin(vi &v, int i, int j)
{
    int globalMax = 0;
    int localMax = 0;
    int globalMin = 0;
    int localMin = 0;
    for (int k = i; k <= j; k++)
    {
        localMax = max(v[k], localMax + v[k]);
        globalMax = max(globalMax, localMax);
        localMin = min(v[k], localMin + v[k]);
        globalMin = min(globalMin, localMin);
    }
    return {globalMin, globalMax};
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
        vi v1 = maxmin(v, 0, n - 1);
        auto &mn = v1[0];
        auto &mx = v1[1];
        cout << mx - mn + 1 el;
        for (int i = mn; i <= mx; i++)
        {
            cout << i ws;
        }
        cout el;
        return;
    }

    vii intervals;

    intervals.push_back(maxmin(v, 0, s - 1));
    intervals.push_back(maxmin(v, s + 1, n - 1));

    vi l = {0, 0};
    int sum = 0;
    for (int i = s - 1; i >= 0; i--)
    {
        sum += v[i];
        l[0] = min(l[0], sum);
        l[1] = max(l[1], sum);
    }

    vi r = {0, 0};
    sum = 0;

    for (int i = s + 1; i < n; i++)
    {
        sum += v[i];
        r[0] = min(r[0], sum);
        r[1] = max(r[1], sum);
    }

    intervals.push_back({l[0] + r[0] + v[s], l[1] + r[1] + v[s]});

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