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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    string s;
    cin >> s;

    int cnt00 = 0;
    int cnt11 = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    if (s[0] == '0')
        cnt0++;
    else
        cnt1++;

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;

        if (s[i - 1] == '0' && s[i] == '0')
        {
            cnt00++;
        }
        if (s[i - 1] == '1' && s[i] == '1')
        {
            cnt11++;
        }

        if (cnt00 == 0 && cnt11 == 0)
        {
            ans++;
            continue;
        }

        if (cnt00 > 1 || cnt11 > 1 || cnt1 == 0 || cnt0 == 0)
        {
            continue;
        }
        if (cnt00 == 1 && cnt11 == 1)
        {
            ans++;
            continue;
        }
        if (cnt00)
        {
            if (s[0] == '1' || s[n - 1] == '1')
            {
                ans++;
            }
        }
        else if (cnt11)
        {
            if (s[0] == '0' || s[n - 1] == '0')
            {
                ans++;
            }
        }
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