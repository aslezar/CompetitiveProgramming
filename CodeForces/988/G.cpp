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

void computePrimeFactors(int MAX, vector<vector<int>> &spf)
{
    for (int i = 2; i < MAX; ++i)
    {
        if (spf[i].empty())
        {
            for (int j = i; j < MAX; j += i)
            {
                spf[j].push_back(i);
            }
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    int MAX = 1e6 + 1;
    vector<vector<int>> spf(MAX);
    computePrimeFactors(MAX, spf);

    vi cnt(n, 0);

    map<int, int> mp;

    for (int i = n - 1; i >= 0; i--)
    {
        auto &factors = spf[v[i]];
        for (int mask = 1; mask < (1 << factors.size()); mask++)
        {
            int pro = 1;
            for (int j = 0; j < factors.size(); j++)
            {
                if (mask & (1 << j))
                {
                    pro *= factors[j];
                }
            }
w
            if (__builtin_popcount(mask) & 1)
            {
                cnt[i] += mp[pro];
            }
            else
            {
                cnt[i] -= mp[pro];
            }
            debug(i, v[i], cnt[i], pro);
            mp[pro]++;
        }
    }
    debug(cnt);
    debug(mp);
    cout << cnt[0] el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}

/*
for (int mask = 1; mask < (1 << factors.size()); mask++)
{
    int prod = 1;
    for (int j = 0; j < factors.size(); j++)
    {
        if (mask & (1 << j))
        {
            prod *= factors[j];
        }
    }
    debug(v[i], prod);
    if (__builtin_popcount(mask) & 1)
        cnt[i] += mp[prod];
    else
        cnt[i] -= mp[prod];
    mp[prod]++;
}
*/