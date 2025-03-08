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

    debug(n);

    vi v(4, 0);
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {

        cout << "?";
        for (int j = 0; j < 4; j++)
        {
            if (j != i)
            {
                cout << " " << j + 1;
            }
        }
        cout << endl;
        cin >> v[i];
        sum += v[i];
    }
    debug(sum);
    sum /= 3;
    for (int i = 0; i < 4; i++)
    {
        v[i] = sum - v[i];
    }

    for (int i = 4; i < n; i++)
    {
        cout << "? 1 2 " << i + 1 << endl;
        int t = 0;
        cin >> t;
        v.push_back(t - v[0] - v[1]);
    }
    debug(v);
    cout << "! ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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