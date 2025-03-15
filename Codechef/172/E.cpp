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

    int m = 0;
    cin >> m;

    vi S(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> S[i];
    }
    debug(S);

    vi A(m + 1, 0);
    vector<pii> mxmn(2);
    for (int i = 1; i <= m; i++)
    {
        A[i] = S[i] - A[i - 1];
        mxmn[i & 1].first = max(mxmn[i & 1].first, A[i]);
        mxmn[i & 1].second = min(mxmn[i & 1].second, A[i]);
    }
    unordered_set<int> vis;
    for (int i = 1; i <= m; i += 2)
    {
        if (vis.find(A[i]) != vis.end())
        {
            cout << 0 << endl;
            return;
        }
        vis.insert(A[i]);
    }

    vis.clear();
    for (int i = 0; i <= m; i += 2)
    {
        if (vis.find(A[i]) != vis.end())
        {
            cout << 0 << endl;
            return;
        }
        vis.insert(A[i]);
    }
    debug(mxmn);
    debug(A);
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