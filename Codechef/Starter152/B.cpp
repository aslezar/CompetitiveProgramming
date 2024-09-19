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

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    ll m = 0;
    cin >> m;
    string s[m];
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll a = 0, b = 0, c = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[j][i] == '0')
            {
                a++;
            }
            else if (s[j][i] == '1')
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        if (a > b)
            swap(a, b);
        assert(a <= b);

        if (a + c <= b)
        {
            a += c;
        }
        else
        {
            a += c;
            int diff = a - b;
            b += diff / 2;
            a -= diff / 2;
        }
        ans += (a * b);
    }
    cout << ans << '\n';
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