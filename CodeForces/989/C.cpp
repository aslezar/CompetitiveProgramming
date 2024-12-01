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

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int parentOf(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = parentOf(parent[node]);
    }
    void unionT(int u, int v)
    {
        int p_u = parentOf(u);
        int p_v = parentOf(v);

        if (p_u == p_v)
            return;

        if (rank[p_u] < rank[p_v])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_u] = p_v;
            rank[p_v]++;
        }
    }
};

pair<int, int> newCell(const char &c, int i, int j)
{
    switch (c)
    {
    case 'U':
        return {i - 1, j};
        break;
    case 'D':
        return {i + 1, j};
        break;
    case 'L':
        return {i, j - 1};
        break;
    case 'R':
        return {i, j + 1};
        break;
    }
    assert(false);
    return {0, 0};
}

bool isOutOfGrid(int i, int j, int n, int m)
{
    return i < 0 || j < 0 || i >= n || j >= m;
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<char>> dp(n, vector<char>(m, 'U'));

    DisjointSet dsu(n * m + 2);

    vector<char> ch = {'U', 'D', 'L', 'R'};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            switch (grid[i][j])
            {
            case 'D':
            case 'R':
                break;
            case '?':
            {
                dp[i][j] = 'U';
                auto [ni, nj] = newCell('U', i, j);
                char uc = 'G';
                if (!isOutOfGrid(ni, nj, n, m))
                {
                    uc = dp[ni][nj];
                    if (uc != 'G')
                    {
                        dsu.unionT(i * m + j, ni * m + nj);
                        dsu.unionT(i * m + j, n * m + 1);
                        dp[i][j] = 'B';
                    }
                }

                auto [ni2, nj2] = newCell('L', i, j);
                char ul = 'G';
                if (!isOutOfGrid(ni2, nj2, n, m))
                {
                    ul = dp[ni2][nj2];
                    if (ul != 'G')
                    {
                        dsu.unionT(i * m + j, ni2 * m + nj2);
                        dsu.unionT(i * m + j, n * m + 1);
                        dp[i][j] = 'B';
                    }
                }
            }
            break;

            case 'U':
            case 'L':
            {
                auto [ni, nj] = newCell(grid[i][j], i, j);
                if (isOutOfGrid(ni, nj, n, m))
                {
                    dp[i][j] = 'G';
                }
                else
                {
                    dp[i][j] = dp[ni][nj];
                    if (dp[i][j] == 'U')
                    {
                        dsu.unionT(i * m + j, n * m + 1);
                        dp[i][j] = dp[ni][nj] = 'B';
                    }
                    dsu.unionT(i * m + j, ni * m + nj);
                }
            }
            break;
            }
        }
    }
    // debug(dp);

    int ans = 0;
    for (int i = 0; i < n * m; i++)
    {
        if (dsu.parentOf(i) == dsu.parentOf(n * m + 1))
        {
            ans++;
        }
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