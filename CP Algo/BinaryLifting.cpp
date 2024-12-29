// https://www.codechef.com/problems/DATA101?tab=statement

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 69;
int n, q;
int a[N], lift[N][21];
pair<int, int> seg[4 * N];

void Build(int l, int r, int pos)
{
    if (l == r)
    {
        seg[pos] = {a[l] + l, l};
        return;
    }

    int mid = (l + r) / 2;
    Build(l, mid, pos * 2);
    Build(mid + 1, r, pos * 2 + 1);

    seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
}

pair<int, int> query(int l, int r, int pos, int ql, int qr)
{
    if (l >= ql && r <= qr)
        return seg[pos];
    else if (l > qr || r < ql)
        return {0, -1};

    int mid = (l + r) / 2;
    return max(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
}

void Solve()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            lift[i][j] = 0;
        }
    }

    for (int i = 0; i <= 4 * n; i++)
    {
        seg[i] = {0, 0};
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    Build(1, n, 1);

    for (int i = 1; i <= n; i++)
    {
        auto get = query(1, n, 1, i, i + a[i]);
        lift[i][0] = get.s;
    }

    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (r < l)
        {
            cout << -1 << "\n";
            continue;
        }
        else if (l == r)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (a[l] + l >= r)
        {
            cout << 1 << "\n";
            continue;
        }

        int ans = 0;
        for (int i = 20; i >= 0; i--)
        {
            if (lift[lift[l][i]][0] < r)
            {
                // cout << l << " ";
                l = lift[l][i];
                //  cout << (1 << i ) << " ";
                //  cout << l << "\n";
                ans += 1 << i;
            }
        }

        if (l + a[l] >= r)
            cout << ans + 1 << "\n";
        else if (lift[l][0] + a[lift[l][0]] >= r)
            cout << ans + 2 << "\n";
        else
            cout << -1 << "\n";
    }
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}