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

void bfs(vector<string> &g, vi &dist, int start)
{
    int n = g.size(), m = g[0].size();

    const vector<pii> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    auto validCell = [&n, &m](int x, int y) -> bool
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (g[node / m][node % m] == '#')
            continue;
        for (auto &[dx, dy] : directions)
        {
            int x = node / m + dx, y = node % m + dy;
            if (validCell(x, y) && g[x][y] == '.' && dist[x * m + y] == INT_MAX)
            {
                dist[x * m + y] = dist[node] + 1;
                q.push(x * m + y);
            }
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, m = 0;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    if (grid[1][0] == '#' || grid[0][1] == '#' || grid[n - 2][m - 1] == '#' || grid[n - 1][m - 2] == '#')
    {
        cout << "-1\n";
        return;
    }

    vi dist1(n * m, INT_MAX); // dist from 0,0
    vi dist2(n * m, INT_MAX); // dist from n-1,m-1

    bfs(grid, dist1, 0);
    bfs(grid, dist2, n * m - 1);

    const int &distance = dist1[n * m - 1];
    if (distance == INT_MAX)
    {
        cout << "-1\n";
        return;
    }

    vector<int> x(n * m + 5, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            auto &d1 = dist1[i * m + j];
            auto &d2 = dist2[i * m + j];
            if (grid[i][j] == '#' || d1 == INT_MAX || d2 == INT_MAX)
                continue;
            if (d1 + d2 == distance)
            {
                x[d1]++;
            }
        }
    }

    for (int i = 1; i < distance; i++)
    {
        if (x[i] == 1)
        {
            cout << distance + 2 << '\n';
            return;
        }
    }

    cout << distance << '\n';
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