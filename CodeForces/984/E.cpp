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
    int n, k, q;
    cin >> n >> k >> q;

    vii v(k, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> v[j][i];
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            v[i][j] = v[i][j] | v[i][j - 1];
        }
    }

    debug(v);

    for (int qq = 0; qq < q; qq++)
    {
        int m;
        cin >> m;

        int s = 0, e = n - 1;
        if (s <= e)
        {

            for (int mm = 0; mm < m; mm++)
            {
                int r;
                char o;
                int c;
                cin >> r >> o >> c;
                r--;

                auto t = upper_bound(v[r].begin() + s, v[r].begin() + e + 1, c) - v[r].begin();
                if (o == '>')
                {
                    s = t;
                }
                else
                {
                    e = t - 1;
                }
                debug(s, e, t);
            }
        }

        if (s <= e)
        {
            cout << s + 1 el;
        }
        else
        {
            cout << -1 el;
        }
    }
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