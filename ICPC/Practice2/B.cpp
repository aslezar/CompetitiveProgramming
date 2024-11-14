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
    ll n = 0;
    cin >> n;

    int k = 0;
    cin >> k;

    int ans = n * (n - 1) / 2;

    map<int, int> s;
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        s[t]++;
    }
    multiset<int, greater<int>> m;
    for (auto &i : s)
    {
        m.insert(i.second);
    }
    for (int i = 0; i < min(k, n); i++)
    {
        auto it = m.begin();
        if (*it == 1)
        {
            break;
        }
        m.erase(it);
        m.insert((*it) - 1);
    }
    for (auto &i : m)
    {
        if (i == 1)
            break;
        ans -= (i * (i - 1) / 2);
    }
    cout << ans el;
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