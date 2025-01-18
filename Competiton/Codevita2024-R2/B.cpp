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

long double dist(pair<long double, long double> a, pair<long double, long double> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<pii> v(n);
    map<int, vi> m;
    int miny = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int &x = v[i].first;
        int &y = v[i].second;
        cin >> x >> y;
        miny = min(miny, y);
        m[x].push_back(y);
    }
    for (auto &i : m)
    {
        sorta(i.second);
    }
    debug(m);
    double ans = 0;
    auto it = m.begin()->second;
    for (int i = 1; i < (int)it.size(); i++)
    {
        int x = m.begin()->first;
        ans += dist({x, it[i - 1]}, {x, it[i]});
    }
    if (m.size() == 1)
    {
        cout << static_cast<int>(round(ans)) << '\n';
        return;
    }
    auto it2 = m.rbegin()->second;
    for (int i = 1; i < (int)it2.size(); i++)
    {
        int x = m.rbegin()->first;
        ans += dist({x, it2[i - 1]}, {x, it2[i]});
    }

    int maxx = INT_MIN;
    int minx = INT_MAX;
    for (auto &i : m)
    {
        if (i.second.front() == miny)
        {
            minx = min(minx, i.first);
            maxx = max(maxx, i.first);
        }
    }

    map<int, int> mp;
    for (auto &i : m)
    {
        mp[i.first] = i.second.front();
    }
    int s = m.begin()->first;

    for (auto &i : mp)
    {
        if (i.first > minx)
            break;
        if (mp[s] > i.second)
        {
            // debug(s, i.first, mp[s], i.second);
            ans += dist({s, mp[s]}, {i.first, i.second});
            s = i.first;
        }
    }

    s = minx;
    for (auto i = mp.upper_bound(minx); i != mp.end(); i++)
    {
        if (i->first > maxx)
            break;
        if (i->second == miny)
        {
            // debug(s, i->first);
            ans += dist({s, mp[s]}, {i->first, i->second});
            s = i->first;
        }
    }

    s = maxx;
    for (auto i = mp.upper_bound(maxx); i != mp.end(); i++)
    {
        if (mp[s] < i->second && i->second <= mp.rbegin()->second)
        {
            // debug(s, i->first);
            ans += dist({s, mp[s]}, {i->first, i->second});
            s = i->first;
        }
    }

    // debug(minx, maxx, miny);

    cout << static_cast<int>(round(ans)) << '\n';
    // debug(ans);
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}