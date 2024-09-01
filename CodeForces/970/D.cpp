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
#define set_bits __builtin_popcount

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

void helper(vi &v, string &s, vi &ans, const int &start, int index, int &curAns)
{
    if (start == index)
    {
        return;
    }

    if (s[index] == '0')
        curAns++;

    helper(v, s, ans, start, v[index] - 1, curAns);
    ans[index] = curAns;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    vi v(n);
    input(v, n);

    vi ans(n, -1);

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == -1)
        {
            int curAns = 0;
            if (s[i] == '0')
                curAns++;
            helper(v, s, ans, i, v[i] - 1, curAns);
            ans[i] = curAns;
        }
    }
    for (auto &i : ans)
        cout << i << ' ';
    cout << endl;
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