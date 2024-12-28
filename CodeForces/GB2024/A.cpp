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

bool ok(int a, int b)
{
    bool ok = true;
    // a a a
    // b b b
    if (2 * a <= a || 2 * b <= b)
        ok = false;

    // a a b
    if (a + a <= b || a + b <= a)
        ok = false;

    // a b b
    if (b + b <= a || b + a <= b)
        ok = false;

    return ok;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        if (i == j)
            continue;
        if (ok(v[i], v[j]))
        {
            debug(v[i], v[j]);
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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