#include <bits/stdc++.h>
using namespace std;

int dp(const vector<int> &a, const int x, const int y, vector<vector<int>> &d)
{
    if (x >= d.size() || y >= d[x].size())
        return -1;
    if (x == y)
        return 0;
    if (x > y)
        return -1;

    if (d[x][y] != INT_MAX)
        return d[x][y];

    int ans = INT_MAX;
    assert(x > 0 && x <= a.size());
    for (int j = 1; j <= a[x - 1]; j++)
    {
        int stepsToReach = dp(a, x + j, y, d);
        if (stepsToReach != -1)
        {
            ans = min(ans, stepsToReach + 1);
        }
    }
    if (ans == INT_MAX)
        return d[x][y] = -1;

    return d[x][y] = ans;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t > 0)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<vector<int>> d(n + 1, vector<int>(n + 1, INT_MAX));
        for (int query = 0; query < q; query++)
        {
            int x, y;
            cin >> x >> y;
            cout << dp(a, x, y, d) << '\n';
        }
        t--;
    }
    return 0;
}
