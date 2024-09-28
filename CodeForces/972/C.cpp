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

const string match = "narek";

int helper(vector<string> &v, int index, int curLeft, vii &dp)
{
    if (index == v.size())
    {
        return -1 * curLeft;
    }

    assert(curLeft < match.size());

    if (dp[index][curLeft] != LLONG_MIN)
    {
        return dp[index][curLeft];
    }

    // skip this string
    int maxScore = helper(v, index + 1, curLeft, dp);

    // take this string
    int score = 0;

    /***** SEE THIS *****/
    int cur = curLeft;

    for (auto &c : v[index])
    {
        if (c == match[cur])
        {
            cur++;
            if (cur == match.size())
            {
                score += match.size();
                cur = 0;
            }
        }
        else
        {
            // if c is in match decrese the score
            if (match.find(c) != string::npos)
            {
                score--;
            }
        }
    }

    maxScore = max(maxScore, score + helper(v, index + 1, cur, dp));
    return dp[index][curLeft] = maxScore;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll m = 0;
    cin >> m;

    vector<string> v(n);
    input(v, n);

    int ans = 0;
    vii dp(n, vi(match.size(), LLONG_MIN));
    ans = helper(v, 0, 0, dp);

    cout << max(0ll, ans) << '\n';
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