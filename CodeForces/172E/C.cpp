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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int diff = 0;
    vi v;
    for (int i = n - 1; i > 0; i--)
    {
        if (s[i] == '0')
            diff--;
        else
            diff++;
        v.push_back(diff);
    }
    sortd(v);
    // debug(v);

    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        sum += v[i];
        if (sum >= k)
        {
            cout << i + 2 el;
            return;
        }
    }

    cout << -1 el;
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