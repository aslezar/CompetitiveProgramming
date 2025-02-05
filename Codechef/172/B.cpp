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
    string a, b;
    cin >> a >> b;

    // int ans = 0;

    vi t;
    t.push_back(-1);
    t.push_back(a.length());

    int k = b.length() - 1;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (b[k] == a[i])
        {
            t.push_back(i);
            k--;
        }
    }
    debug(k);
    sorta(t);
    debug(t);
    if (k != -1)
    {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;

    for (int i = 1; i < t.size(); i++)
    {
        ans += ((t[i] - t[i - 1] - 1) * i);
    }

    cout << ans << '\n';
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