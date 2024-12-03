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

    vector<pii> v(n);

    vector<pii> start;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        v[i] = {l, r};
        start.push_back({l, r});
    }
    sort(all(start), [](pii &a, pii &b)
         {if(a.first==b.first)return a.second>b.second;return a.first<b.first; });

    // debug(start);

    map<pii, pii> ans;

    set<int> m;
    for (int i = 0; i < n; i++)
    {
        auto it = m.lower_bound(start[i].second);
        if (it == m.end())
            ans[start[i]].second = -1;
        else
            ans[start[i]].second = *it;

        m.insert(start[i].second);
    }

    sort(all(start), [](pii &a, pii &b)
         {if(a.second==b.second)return a.first<b.first;return a.second>b.second; });

    // debug(start);
    // debug(ans);

    m.clear();
    for (int i = 0; i < n; i++)
    {
        auto it = m.upper_bound(start[i].first);
        if (it == m.begin())
            ans[start[i]].first = -1;
        else
        {
            it--;
            ans[start[i]].first = *it;
        }

        m.insert(start[i].first);
    }

    // debug(ans);

    for (auto &p : v)
    {
        auto &curAns = ans[p];
        if (curAns.first == -1 || curAns.second == -1)
        {
            cout << 0 el;
        }
        else
        {
            cout << curAns.second - curAns.first - p.second + p.first el;
        }
    }
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