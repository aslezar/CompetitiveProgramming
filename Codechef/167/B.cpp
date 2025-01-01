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

    set<int> s;
    int t = 0;
    int no = 0;
    cin >> no;
    s.insert(no);
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        s.insert(t);
    }

    int l = no, r = no;
    auto it = s.upper_bound(no);
    if (it == s.end())
    {

        r = 1e6;
    }
    else
    {
        int d = *it - no - 1;
        d = (d + 1) / 2;
        r = no + d;
    }

    auto it2 = s.lower_bound(no);
    if (it2 == s.begin())
    {
        l = 1;
    }
    else
    {
        it2--;
        int d = no - *it2 - 1;
        d = (d + 1) / 2;
        l = no - d;
    }
    debug(l, r);
    cout << (r - l + 1) el;
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