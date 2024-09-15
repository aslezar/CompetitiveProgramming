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

    ll t1, t2;
    cin >> t1 >> t2;

    ll d;
    cin >> d;

    if (t2 < t1)
        swap(t1, t2);

    debug(t1, t2, d);
    assert(t2 > t1);

    if (t1 < d && d < t2)
    {
        ll m = (t2 + t1) / 2;
        cout << m - t1 << endl;
    }
    else if (t1 > d)
    {
        cout << t1 - 1 << endl;
    }
    else if (d > t2)
    {
        cout << n - t2 << endl;
    }
    else
    {
        assert(false);
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