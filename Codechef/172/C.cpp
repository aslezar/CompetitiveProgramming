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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    map<int, int> m;
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
        {
            if (v[i] == 0)
            {
                // pq.push({i, 0});
                m[i] = 0;
            }
        }
        else
        {
            if (v[i] == 1)
            {
                // pq.push({i, 0});
                m[i] = 1;
            }
        }
    }

    int q = 0;
    cin >> q;
    for (int qq = 0; qq < q; qq++)
    {
        int p, x;
        cin >> p >> x;
        p--;
        v[p] = x;

        m.erase(p);

        if (p & 1)
        {
            if (v[p] == 0)
            {
                m[p] = 0;
            }
        }
        else
        {
            if (v[p] == 1)
            {
                m[p] = 1;
            }
        }

        if (m.size() > 0)
        {
            cout << m.rbegin()->second << '\n';
        }
        else
        {
            if (n == 1)
            {
                cout << v[0] << '\n';
            }
            else
            {
                debug(v);
                cout << (v[0] & v[1]) << '\n';
            }
        }
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