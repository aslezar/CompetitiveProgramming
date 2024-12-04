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
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if (m > n || s[0] != t[0] || s.back() != t.back())
    {
        cout << "No\n";
        return;
    }
    if (m == n)
    {
        cout << (s == t ? "Yes\n" : "No\n");
        return;
    }

    if (count(all(s), 'A') % n == 0)
    {
        cout << "No\n";
        return;
    }

    vi sc;
    vi tc;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] != s[i])
        {
            sc.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    sc.push_back(cnt);
    cnt = 1;
    for (int i = 1; i < m; i++)
    {
        if (t[i - 1] != t[i])
        {
            tc.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    tc.push_back(cnt);

    if (tc.size() != sc.size())
    {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < sc.size(); i++)
    {
        if (sc[i] - tc[i] < 0 || (sc[i] & 1) != (tc[i] & 1))
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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