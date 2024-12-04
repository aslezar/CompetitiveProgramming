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

int val(int u, int n)
{
    if (u == 0)
        return 0;
    if (n == 0)
        return 0;
    if (n == 1)
    {
        return u;
    }
    return u + val(u / 2, n - 1);
}

void solve([[maybe_unused]] ll &_case_no)
{
    int x, n;
    cin >> x >> n;

    int l = 1, r = x;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int value = val(mid, n);
        if (value == x)
        {
            cout << mid << '\n';
            return;
        }
        if (value < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << -1 el;
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