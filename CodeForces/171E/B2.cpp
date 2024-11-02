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

    if (n == 1)
    {
        cout << 1 el;
        return;
    }

    if (n % 2 == 0)
    {
        vi s;
        for (int i = 0; i < n; i += 2)
        {
            s.push_back(v[i + 1] - v[i]);
        }
        int ans = *max_element(all(s));
        cout << ans el;
        return;
    }

    vi s;
    vi s1;
    vi s2;
    for (int i = 1; i < n; i++)
    {
        s.push_back(v[i] - v[i - 1]);
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            s1.push_back(s[i]);
        }
        else
        {
            s2.push_back(s[i]);
        }
    }

    int mx = s1.front();
    for (int i = 0; i < s1.size(); i++)
    {
        mx = max(mx, s1[i]);
        s1[i] = mx;
    }

    mx = s2.back();
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        mx = max(mx, s2[i]);
        s2[i] = mx;
    }
    debug(s1);
    debug(s2);

    assert(s1.size() == s2.size());

    int ans = LLONG_MAX;
    int n2 = s2.size();
    for (int i = 0; i + 1 < s2.size(); i++)
    {
        ans = min(ans, max(s1[i], s2[i + 1]));
    }
    ans = min(ans, *max_element(all(s1)));
    ans = min(ans, *max_element(all(s2)));
    cout << ans el;
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