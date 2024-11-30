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
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << "Yes\n";
        return;
    }

    int t1 = count(all(s), 'a');
    int t2 = count(all(t), 'a');

    if (t1 != t2)
    {
        cout << "No\n";
        return;
    }

    if (t1 == 0)
    {
        if (n == m)
        {
            cout << "Yes\n";
        }
        else
        {

            cout << "No\n";
        }
        return;
    }

    int i = 0, j = 0;

    while (i < n && s[i] != 'a')
        i++;
    while (j < m && t[j] != 'a')
        j++;

    if (i != j)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
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