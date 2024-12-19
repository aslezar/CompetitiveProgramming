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
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;

    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;

    int k;
    cin >> k;

    vi z = {abs(x1 - x2), abs(y1 - y2), abs(z1 - z2)};
    sortd(z);
    debug(z);

    int mn = z[0] + z[1] + z[2];
    debug(mn);

    int sum = z[0] + z[1] + z[2];
    int mx = *max_element(all(z));
    sum -= mx;
    mx = (mx + k - 1) / k;
    mx--;
    mx -= sum;
    if (mx > 0)
    {
        mn += mx;
        if (mx % 2 == 1)
        {
            mn++;
        }
    }

    cout << mn el;
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