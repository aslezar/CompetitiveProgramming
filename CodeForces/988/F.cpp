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
    int n, m, k;
    cin >> n >> m >> k;

    vi h(n);
    input(h, n);

    vi x(n);
    input(x, n);

    auto isValid = [&](int op) -> bool
    {
        vector<pair<int, int>> intrvls;
        for (int i = 0; i < n; i++)
        {
            int range = m - ceil(h[i] * 1.0 / op);
            if (range < 0)
                continue;
            intrvls.push_back({max(0ll, x[i] - range), min(ll(1e9), x[i] + range)});
        }

        map<int, int> mp;
        for (auto &i : intrvls)
        {
            mp[i.first]++;
            mp[i.second + 1]--;
        }

        if (_case_no == 4)
        {
            // debug( intrvls, mp);
        }
        int curK = 0;
        for (auto &i : mp)
        {
            curK += i.second;
            if (curK >= k)
                return true;
        }
        return false;
    };

    int l = 1, r = 1e9;
    int ans = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // debug(mid);
        bool possible = isValid(mid);
        // debug(mid,possible);
        if (possible)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (ans == INT_MAX)
    {
        cout << -1 el;
        return;
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