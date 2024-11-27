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

int count(vi &c)
{
    vi a = {c[0], c[1]};
    int ans = 0;

    for (int i = 2; i < c.size(); i++)
    {
        if (c[i] <= a[0] + a[1])
        {
            ans++;
        }
        a.push_back(c[i]);
        sortd(a);
        a.pop_back();
    }
    return ans;
}

vector<unordered_map<int, int>> dp;
int helper(int i, vi &v, vi &v2, int a, int b)
{
    if (i == v.size())
    {
        return 0;
    }

    if (dp[i].count(a + b))
    {
        return dp[i][a + b];
    }

    vi v3 = {a, b};
    v3.push_back(v[i]);
    sortd(v3);
    int ans1 = helper(i + 1, v, v2, v3[0], v3[1]);
    if (v[i] <= a + b)
    {
        ans1++;
    }

    vi v4 = {a, b};
    v4.push_back(v2[i]);
    sortd(v4);
    int ans2 = helper(i + 1, v, v2, v4[0], v4[1]);
    if (v2[i] <= a + b)
    {
        ans2++;
    }
    // return max(ans1, ans2);
    return dp[i][a + b] = max(ans1, ans2);
}
int ans = 0;
void backtrack(int i, vi &a, vi &b, vi &c)
{
    if (i >= a.size())
    {
        int curAns = count(c);
        ans = max(ans, curAns);
        if(ans==3){
            debug(c);
        }
        return;
    }

    c.push_back(a[i]);
    backtrack(i + 1, a, b, c);
    c.pop_back();

    c.push_back(b[i]);
    backtrack(i + 1, a, b, c);
    c.pop_back();
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    vi v2(n);
    input(v2, n);

    ans = 0;
    vi c;
    backtrack(0, v, v2, c);
    cout << ans el

    // dp = vector<unordered_map<int, int>>(3001);

    // int ans = 0;
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         ans = max(ans, helper(2, v, v2, max(v[i], v2[j]), min(v[i], v2[j])));
    //     }
    // }
    // cout << ans el
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