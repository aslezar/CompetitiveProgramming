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

pii solve(int l, int r, const int &k)
{
    if (l > r || l <= 0 || r <= 0)
        return {0, 0};

    int len = r - l + 1;
    if (len < k)
        return {0, 0};
    if (l == r)
        return {l, 1};

    int mid = (l + r) / 2;
    int ans = 0;
    int count = 0;
    if (len & 1)
    {
        auto [left, left_count] = solve(l, mid - 1, k);

        int m = mid * left_count;

        ans = left + mid + (m + m - left);
        count = (2 * left_count) + 1;
    }
    else
    {
        auto [left, left_count] = solve(l, mid, k);

        long long m = ((2 * mid) + 1) * left_count;

        ans = left + (m - left);
        count = 2 * left_count;
    }
    return {ans, count};
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n, k;
    cin >> n >> k;

    int luck = solve(1, n, k).first;
    cout << luck el;
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