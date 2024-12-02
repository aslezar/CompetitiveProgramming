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

bool isPossible(int &n, string &s, int &k, int mid)
{

    int m = mid;

    int i = n - 1;
    int ans = 0;
    int cnt[2] = {0};
    while (i >= 0 && m > 0)
    {
        cnt[s[i] - '0']++;
        if (cnt[1] > cnt[0] || i == m)
        {
            while (i > m && s[i - 1] == '1')
            {
                cnt[s[i] - '0']++;
                i--;
            }
            int diff = cnt[1] - cnt[0];
            debug(i, diff, m);
            ans += (diff * m);
            m--;
            cnt[0] = 0;
            cnt[1] = 0;
        }
        i--;
    }

    debug(ans, mid);

    return ans >= k;
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int l = 0, r = n - 1;
    int ans = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (isPossible(n, s, k, mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (ans == INT_MAX)
    {
        cout << -1 el;
        return;
    }
    cout << ans + 1 el;
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