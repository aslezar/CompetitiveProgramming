/* Berland shop sells n kinds of juices. Each juice has its price ci

. Each juice includes some set of vitamins in it. There are three types of vitamins: vitamin "A", vitamin "B" and vitamin "C". Each juice can contain one, two or all three types of vitamins in it.

Petya knows that he needs all three types of vitamins to stay healthy. What is the minimum total price of juices that Petya has to buy to obtain all three vitamins? Petya obtains some vitamin if he buys at least one juice containing it and drinks it. */

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

vii dp;
int helper(vector<pair<int, int>> &c, int index, int mask)
{

    if (index >= c.size())
    {
        return mask == 7 ? 0 : INT_MAX;
    }

    auto &dpV = dp[index][mask];
    if (dpV != -1)
        return dpV;

    // not include
    int cost = helper(c, index + 1, mask);

    // include
    cost = min(cost, helper(c, index + 1, mask | c[index].second) + c[index].first);
    return dpV = cost;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> c[i].first >> s;
        c[i].second = 0;
        for (auto &ch : s)
        {
            c[i].second |= (1 << (ch - 'A'));
        }
    }
    dp = vii(n, vi(8, -1));
    int ans = helper(c, 0, 0);
    cout << (ans == INT_MAX ? -1 : ans) el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;

#ifdef LOCAL_RUN
    // cin >> t;
#endif

    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}