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

vi dp;

int helper(vector<pair<string, int>> &str, string &main, int index)
{
    if (index >= (int)(main.size()))
    {
        return 0;
    }
    if (dp[index] != -1)
        return dp[index];
    int ans = INT_MAX;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (index + (unsigned int)str[i].first.size() > main.size())
            continue;
        if (main.substr(index, str[i].first.length()) == str[i].first)
        {
            for (int k = 0; k < (int)str[i].first.size(); k++)
            {
                int curAns = min(ans, helper(str, main, index + k + 1));
                if (curAns != INT_MAX)
                {
                    ans = min(ans, curAns + str[i].second);
                }
            }
        }
    }
    return dp[index] = ans;
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n = 0;
    cin >> n;

    vector<pair<string, int>> str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i].first >> str[i].second;
    }
    string main;
    cin >> main;

    dp = vi(main.size(), -1);

    int ans = helper(str, main, 0);
    debug(dp);
    if (ans == INT_MAX)
    {
        cout << "Impossible";
        return;
    }
    cout << ans;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}