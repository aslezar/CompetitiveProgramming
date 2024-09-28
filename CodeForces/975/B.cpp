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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll q = 0;
    cin >> q;

    vi v(n);
    input(v, n);

    // vi ans((1e18) * 1ll, 0);
    safe_map<ll, int> ans;

    ll prev = n - 1;
    ans[prev]++;

    for (ll i = 1; i < n; i++)
    {
        ll curVal = prev - i + 1;
        ll noBetweenPrevAndNext = v[i] - v[i - 1] - 1;
        ans[curVal] += noBetweenPrevAndNext;

        curVal += n - i - 1;

        ans[curVal]++;
        prev = curVal;
    }

    for (ll qq = 0; qq < q; qq++)
    {
        ll k;
        cin >> k;

        cout << ans[k] << ' ';
    }
    cout << '\n';
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