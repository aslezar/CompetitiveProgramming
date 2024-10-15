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

int dp[5001][5001];
vi z[2][5001];

int helper(int &m, int index, int strength)
{
    if (index >= m)
    {
        return 0;
    }
    if (dp[index][strength] != -1)
        return dp[index][strength];

    int intelligence = index - strength;

    int winsA = upper_bound(all(z[0][index]), strength + 1) - z[0][index].begin();
    winsA += upper_bound(all(z[1][index]), intelligence) - z[1][index].begin();
    winsA += helper(m, index + 1, strength + 1);

    int winsB = upper_bound(all(z[0][index]), strength) - z[0][index].begin();
    winsB += upper_bound(all(z[1][index]), intelligence + 1) - z[1][index].begin();
    winsB += helper(m, index + 1, strength);

    return dp[index][strength] = max(winsA, winsB);
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll m = 0;
    cin >> m;

    vi v(n);
    input(v, n);

    // for (int i = 0; i < 2; i++)
    //     for (int j = 0; j <= 5000; j++)
    //         z[i][j].clear();

    int cnt = -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            cnt++;
        else if (cnt != -1)
            z[v[i] > 0][cnt].push_back(abs(v[i]));
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < m; j++)
            sorta(z[i][j]);

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;

    cout << helper(m, 0, 0) el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    // cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}