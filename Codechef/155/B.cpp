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

    ll m = 0;
    cin >> m;

    int index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < index; j++)
        {
            cout << "2 ";
        }
        cout << "3 ";
        for (int j = index + 1; j < m; j++)
        {

            cout << "2 ";
        }
        cout << endl;
        index = (index + 1) % m;
    }

    if (n <= m)
    {
        for (int i = 0; i < index; i++)
        {

            cout << "2 ";
        }
        for (int i = index; i < m; i++)
        {

            cout << "3 ";
        }
        cout << endl;
    }
    else
    {
        cout << "3 ";
        for (int i = 1; i < m; i++)
        {

            cout << "2 ";
        }
        cout << endl;
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