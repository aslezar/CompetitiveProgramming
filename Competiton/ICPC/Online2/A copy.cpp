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

    sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    debug(queries);

    vector<int> ans(n, -1);
    for (auto &q : queries)
    {
        for (int i = q[0]; i <= q[1]; i++)
        {
            ans[i - 1] = q[2];
        }
    }

    for (auto &i : ans)
    {
        if (i == -1)
            ans[i] = n;
    }

    for (auto &q : queries)
    {
        int mn = *min_element(ans.begin() + q[0] - 1, ans.begin() + q[1]);
        if (mn != q[2])
        {
            cout << -1 el;
            return;
        }
    }
    for (auto &i : ans)
    {
        cout << i << " ";
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