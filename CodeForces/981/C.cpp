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

    vi v(n);
    input(v, n);

    for (int i = 1; i < n / 2; i++)
    {
        int j = n - i - 1;
        // v[i],v[j]
        if (v[i] == v[j])
            continue;
        if (v[i - 1] == v[i])
        {
            swap(v[i], v[j]);
        }
        else if (v[j + 1] == v[j])
        {
            swap(v[i], v[j]);
        }
    }
    // debug(v);
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] == v[i])
            cnt++;
    }
    cout << cnt el;
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