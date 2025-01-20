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

    int m1, m2;
    cin >> m1 >> m2;

    set<pii> s;
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cin >> a >> b;
        pii p = {min(a, b), max(a, b)};
        s.insert(p);
    }

    for (int i = 0; i < m2; i++)
    {
        int a, b;
        cin >> a >> b;
        pii p = {min(a, b), max(a, b)};
        if (s.count(p))
        {
            s.erase(p);
        }
        else
        {
            s.insert(p);
        }
    }
    cout << s.size() el;
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