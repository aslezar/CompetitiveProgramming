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

    vi v(n);
    input(v, n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    bool pos = sum > 0;
    sum = abs(sum);
    if (sum == 0)
    {
        cout << -1 << endl;
        return;
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            continue;
        mx = max(mx, i + v[i]);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < min(sum, n); i++)
    {
        pq.push(v[i]);
    }
    while (sum < mx)
    {
        int x = pq.top();
        pq.pop();
        x++;
        pq.push(x);
        sum++;
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