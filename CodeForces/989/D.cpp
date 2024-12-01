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
#define ws << " "

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

    vector<pair<int, int>> moves;

    set<int> idx[3];
    vi cnt(3);
    for (int i = 0; i < n; i++)
    {
        cnt[v[i]]++;
        idx[v[i]].insert(i);
    }

    // Check if every no are in correct index limit.
    while ((idx[2].size() && *idx[2].begin() < cnt[0] + cnt[1]) || (*idx[1].begin() < cnt[0]))
    {
        // if 1 have higher index than swap it with 2
        if (idx[2].size() && *idx[1].rbegin() >= cnt[1] + cnt[0])
        {
            int i = *idx[1].rbegin();
            int j = *idx[2].begin();

            idx[1].erase(i);
            idx[2].erase(j);

            idx[1].insert(j);
            idx[2].insert(i);

            moves.push_back({i, j});
        }

        // if 0 have higher index than swap it with 1
        if (idx[0].size() && *idx[0].rbegin() >= cnt[0])
        {
            int i = *idx[0].rbegin();
            int j = *idx[1].begin();

            idx[0].erase(i);
            idx[1].erase(j);

            idx[0].insert(j);
            idx[1].insert(i);

            moves.push_back({i, j});
        }
    }

    cout << moves.size() el;
    for (auto [a, b] : moves)
    {
        cout << a + 1 ws << b + 1 el;
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