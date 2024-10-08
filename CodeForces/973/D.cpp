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
    vi v(n);
    input(v, n);

    stack<pair<ll, ll>> s;
    for (size_t i = 0; i < n; i++)
    {
        ll sum = v[i], cnt = 1;
        while (s.size() && s.top().first >= (sum / cnt))
        {
            auto t = s.top();
            s.pop();
            sum += (t.first * t.second);
            cnt += t.second;
        }
        if (sum % cnt == 0)
        {
            s.push({sum / cnt, cnt});
        }
        else
        {
            s.push({sum / cnt, cnt - sum % cnt});
            s.push({sum / cnt + 1, sum % cnt});
        }
    }

    ll mn = LLONG_MAX;
    ll mx = LLONG_MIN;

    while (!s.empty())
    {
        mn = min(mn, s.top().first);
        mx = max(mx, s.top().first);
        s.pop();
    }
    cout << (mx - mn) << '\n';
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