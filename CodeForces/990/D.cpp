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

typedef pair<int, int> pii;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back({v[i], i});
    }
    sorta(a);
    debug(a);

    priority_queue<int, vector<int>, greater<int>> pq;
    vi ans;

    int f = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second > f)
        {
            if (pq.empty() || a[i].first <= pq.top() + 1)
            {
                ans.push_back(a[i].first);
            }
            else
            {
                pq.push(a[i].first);
            }
        }
        else
        {
            pq.push(a[i].first);
        }
        f = max(f, a[i].second);
    }
    debug(ans);

    while (!pq.empty())
    {
        ans.push_back(pq.top() + 1);
        pq.pop();
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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