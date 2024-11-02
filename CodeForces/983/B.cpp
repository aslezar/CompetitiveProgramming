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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll k = 0;
    cin >> k;

    if (n == 1)
    {
        cout << "1\n1\n";
        return;
    }

    if (k == 1 || k == n)
    {
        cout << -1 el;
        return;
    }

    if (n == 3)
    {
        cout << "3\n1 2 3" el;
        return;
    }

    if (k % 2 == 0)
    {
        cout << "3\n";
        cout << "1 " << k << ' ' << k + 1 el;
    }
    else
    {
        cout << "5\n";
        cout << "1 2 " << k << ' ' << k + 1 << ' ' << n el;
    }
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