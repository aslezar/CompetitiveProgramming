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
    string n;
    cin >> n;

    int sum = 0;
    unordered_map<char, int> f;
    for (int i = 0; i < (int)n.length(); i++)
    {
        sum += (n[i] - '0');
        if (n[i] == '2' || n[i] == '3')
            f[n[i]]++;
    }

    int rem = sum % 9;

    int count2 = f['2'];
    int count6 = f['3'];

    bool ok = false;
    for (int i = 0; i <= min(count2, 8ll); i++)
    {
        for (int j = 0; j <= min(count6, 8ll); j++)
        {
            if ((rem + 2 * i + 6 * j) % 9 == 0)
            {
                ok = true;
                break;
            }
        }
    }

    if (ok)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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