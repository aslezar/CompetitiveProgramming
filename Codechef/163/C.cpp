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

vii dp;

int helper(int index, bool pc, string &s, map<char, char> &m)
{
    if (index >= (int)s.size())
    {
        return 0;
    }

    if (dp[index][pc] != -1)
        return dp[index][pc];

    char prevChar = s[index - 1];
    if (pc == true)
    {
        prevChar = m[prevChar];
    }

    char curChar = s[index];

    int ans = INT_MAX;
    // don't change
    if (prevChar <= curChar)
    {
        ans = helper(index + 1, false, s, m);
    }
    curChar = m[curChar];
    // change
    if (prevChar <= curChar)
    {
        int curAns = helper(index + 1, true, s, m);
        if (curAns != INT_MAX)
        {
            ans = min(ans, curAns + 1);
        }
    }
    return dp[index][pc] = ans;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    string s, p;
    cin >> s >> p;

    map<char, char> m;
    for (int i = 0; i < 26; i++)
    {
        int t = 26 - i - 1;
        m[p[i]] = p[t];
    }
    // debug(m);

    dp = vii(n + 1, vi(2, -1));

    int ans = INT_MAX;
    ans = min(ans, helper(1, false, s, m));
    ans = min(ans, helper(1, true, s, m) + 1);
    // cout << ans el;
    if (ans == INT_MAX)
    {
        cout << -1 el;
    }
    else
    {
        cout << ans el;
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