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
#define set_bits __builtin_popcount

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n, m, q;
    cin >> n >> m >> q;

    set<int> t;
    ll temp = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        t.insert(temp);
    }

    for (int qq = 0; qq < q; qq++)
    {
        ll d;
        cin >> d;
        auto t1_itr = t.lower_bound(d);
        auto t2_itr = t.upper_bound(d);

        if (t1_itr == t.begin())
        {
            // ans[d] = ((*t.begin()) - 1);
            cout << ((*t.begin()) - 1) << '\n';
        }
        else if (t2_itr == t.end())
        {
            // ans[d] = n - (*t.rbegin());
            cout << n - (*t.rbegin()) << '\n';
        }
        else
        {
            --t1_itr;
            ll m = ((*t2_itr) + *(t1_itr)) / 2;
            // ans[d] = m - (*t1_itr);
            cout << m - (*t1_itr) << '\n';
        }
        // cout << ans[d] << '\n';
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