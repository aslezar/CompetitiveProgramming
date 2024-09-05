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

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll k = 0;
    cin >> k;

    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == s2)
    {
        cout << "0" << '\n';
        return;
    }

    vector<pair<int, char>> steps;

    int l = 0, r = 0;
    unordered_map<char, int> f;
    for (int i = 0; i < k; i++)
    {
        f[s2[i]]++;
    }
    if (f[s2[0]] == k)
    {
        // Substr found;
        l = 0, r = k;
    }
    else
    {
        for (int i = k; i < n; i++)
        {
            f[s2[i]]++;
            f[s2[i - k]]--;
            if (f[s2[i]] == k)
            {
                l = i - k + 1, r = i + 1;
                // while (r < n && s2[r - 1] == s2[r])
                // {
                //     r++;
                // }
                break;
            }
        }
        if (r - l < k)
        {
            cout << "-1" << '\n';
            return;
        }
    }
    debug(l, r);
    // assert(r - l >= k);

    for (int i = 0; i < l; i++)
    {
        assert(i + 1 >= 1 && i + 1 <= n - k + 1);
        steps.push_back({i + 1, s2[i]});
    }

    for (int i = n - 1; i >= r; i--)
    {
        assert(i - k + 2 >= 1 && i - k + 2 <= n - k + 1);
        steps.push_back({i - k + 2, s2[i]});
    }
    steps.push_back({l + 1, s2[l]});

    assert(static_cast<ll>(steps.size()) <= 2 * n);
    cout << steps.size() << '\n';
    for (auto &i : steps)
    {
        cout << i.first << ' ' << i.second << '\n';
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