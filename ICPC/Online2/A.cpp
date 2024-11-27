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

    int k = 0;
    cin >> k;

    vii queries(k, vector<int>(3));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }
    }

    vector<set<int>> v(n);

    for (auto q : queries)
    {
        for (int i = q[0]; i <= q[1]; i++)
        {
            v[i - 1].insert(q[2]);
        }
    }
    vi ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (v[i].size() == n)
        {
            cout << -1 el;
            return;
        }
        for (int j = 1; j <= n; j++)
        {
            if (v[i].find(j) == v[i].end())
            {
                ans[i] = j;
                break;
            }
        }
    }
    for (auto a : ans)
    {
        cout << a ws;
    }
    cout el;
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