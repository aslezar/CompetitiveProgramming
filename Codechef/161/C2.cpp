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

bool isValid(vi &v, int m, int k)
{
    int array = 1;
    int l1 = v[0] - m;
    int r1 = v[0] + m;
    for (int i = 1; i < v.size(); i++)
    {
        int l = v[i] - m;
        int r = v[i] + m;
        if (min(r1, r) < max(l1, l))
        {
            array++;
            if (array > k)
                return false;
            l1 = l;
            r1 = r;
        }
        else
        {
            l1 = max(l1, l);
            r1 = min(r1, r);
        }
    }
    return true;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    int k = 0;
    cin >> k;

    vi v;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;
        if (v.empty() || v.back() != t)
        {
            v.push_back(t);
        }
    }
    n = v.size();
    if (n - 1 <= k)
    {
        cout << 0 el;
        return;
    }

    int ans = INT_MAX;
    int l = 0, r = 1e9;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (isValid(v, mid, k + 1))
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            l = mid + 1;
        }
    }
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