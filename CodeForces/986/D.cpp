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

    vii v(3, vi(n + 1));
    vector<pair<int, int>> mn(3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
        mn[i] = {v[i][1], 1};
    }

    vector<pair<int, int>> soln(n + 1, {-1, -1});

    for (int j = 2; j <= n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (mn[i].first > v[i][j])
            {
                soln[j] = {i, mn[i].second};
                for (int i = 0; i < 3; i++)
                {
                    if (mn[i].first < v[i][j])
                    {
                        mn[i] = {v[i][j], j};
                    }
                }
                break;
            }
        }
    }
    debug(soln);

    vector<pair<int, int>> ans;
    int start = n;

    while (start != 1)
    {
        if (start == -1)
        {
            cout << "No\n";
            return;
        }
        ans.push_back({soln[start].first, start});
        start = soln[start].second;
    }
    cout << "Yes\n";
    cout << ans.size() el;
    const string s = "qkj";

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << s[ans[i].first] << ' ' << ans[i].second el;
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