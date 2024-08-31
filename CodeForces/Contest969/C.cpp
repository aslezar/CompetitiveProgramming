#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount
#define gcd __gcd

constexpr unsigned int mod = 1e9 + 7;
constexpr ll maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

void helper(set<ll> &s, ll &ans, ll a, ll b, vector<ll> &v)
{
    ll mn = *s.begin();
    ll mx = *s.rbegin();

    // remove mn and mx
    s.erase(mn);
    s.erase(mx);

    vector<pair<ll, ll>> arr;
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v.size(); j++)
        {
            arr.push_back({mn + v[i], mx + v[j]});
        }
    }

    // range and index
    vector<pair<ll, ll>> minFoundAt;

    for (size_t i = 0; i < arr.size(); i++)
    {
        bool isArrIFirstExists = !s.insert(arr[i].first).second;
        bool isArrISecondExists = !s.insert(arr[i].second).second;

        ll range = *s.rbegin() - *s.begin();
        // debug(arr[i].first, arr[i].second, range);
        if (range < ans)
        {
            minFoundAt.push_back({range, i});
        }
        if (isArrIFirstExists == false)
            s.erase(arr[i].first);
        if (isArrISecondExists == false)
            s.erase(arr[i].second);
    }

    if (minFoundAt.empty())
        return;

    auto minValueAt = *min_element(minFoundAt.begin(), minFoundAt.end());
    ans = min(ans, minValueAt.first);
    // debug(s);

    for (size_t i = 0; i < minFoundAt.size(); i++)
    {
        if (minFoundAt[i].first == minValueAt.first)
        {
            bool isArrIFirstExists = !s.insert(arr[minValueAt.second].first).second;
            bool isArrISecondExists = !s.insert(arr[minValueAt.second].second).second;
            helper(s, ans, a, b, v);
            if (isArrIFirstExists == false)
                s.erase(arr[minValueAt.second].first);
            if (isArrISecondExists == false)
                s.erase(arr[minValueAt.second].second);
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n, a, b;
    cin >> n >> a >> b;

    set<ll> s;

    ll val = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> val;
        s.insert(val);
    }

    if (abs(a - b) == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (a > b)
        swap(a, b);

    vector<ll> v = {0, a, b};

    ll ans = *s.rbegin() - *s.begin();
    helper(s, ans, a, b, v);

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