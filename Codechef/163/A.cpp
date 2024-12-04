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

    int x;
    cin >> x;

    vi a(n);
    input(a, n);

    vi b(n);
    input(b, n);

    // mul<int, greater<int>> s;
    priority_queue<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(a[i] * b[i]);
    }

    int ans = 0;
    while (x > 0 && s.size() > 0)
    {
        x -= s.top();
        s.pop();
        ans++;
    }
    if (x > 0)
    {
        cout << -1 el;
    }
    else
    {
        cout << ans el;
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