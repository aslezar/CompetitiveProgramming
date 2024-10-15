#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
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
    ll n = 0;
    cin >> n;

    ll k = 0;
    cin >> k;

    vi v(n);
    input(v, n);

    int maxV = *max_element(all(v));

    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }

    int ans = 0;
    int curSum = 0;
    int l = 0;
    for (int r = 1; r <= maxV; r++)
    {
        if (freq.count(r) == 0)
        {
            curSum = 0;
            r = freq.upper_bound(r)->first - 1;
            l = r;
            continue;
        }
        curSum += freq[r];
        while (r - l >= k)
        {
            curSum -= freq[l];
            l++;
        }
        // debug(curSum, l, r);
        ans = max(ans, curSum);
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