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
constexpr unsigned int mod = 998244353;

const int maxn = 1e6 + 1;
vi spf[maxn];
void calcaulte_factors()
{
    for (int i = 2; i < maxn; i++)
    {
        if (spf[i].empty())
        {
            for (int j = i; j < maxn; j += i)
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

    map<int, int> sum;
    vi cnt(n);
    cnt[0] = 1;

    auto &factors = spf[v[0]];
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

        sum[pro]++;
    }

    for (int i = 1; i < n; i++)
    {
        auto &factors = spf[v[i]];
        vi div;
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
            div.push_back(pro);
            if (__builtin_popcount(mask) & 1)
            {
                cnt[i] = (cnt[i] + sum[pro]) % mod;
            }
            else
            {
                cnt[i] = (cnt[i] - sum[pro] + mod) % mod;
            }
        }
        for (auto &pro : div)
        {
            sum[pro] = (sum[pro] + cnt[i]) % mod;
        }
    }
    debug(cnt);
    cout << cnt[n - 1] el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    calcaulte_factors();
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}