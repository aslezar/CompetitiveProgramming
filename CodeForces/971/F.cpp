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

ll shiftArraySum(vector<int> &preSum, ll shift, ll l, ll r, ll n)
{
    if (l > r || l < 0 || r >= n)
        return 0;

    // debug(preSum, shift, l, r, n);

    ll sum = 0;

    l += shift;
    r += shift;

    if (l < n && r >= n)
    {
        sum += preSum[n] - preSum[l];
        sum += preSum[r % n + 1];
        return sum;
    }

    l %= n;
    r %= n;

    // debug(l, r);

    sum += (preSum[r + 1] - preSum[l]);

    // debug(sum);
    return sum;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, q = 0;
    cin >> n >> q;
    vi v(n);
    input(v, n);

    ll arraySum = 0;
    vi preSum;
    preSum.push_back(0);

    for (int i = 0; i < n; i++)
    {
        arraySum += v[i];
        preSum.push_back(arraySum);
    }

    FOR(qq, 1, q)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;

        ll l_shift = l / n;
        ll r_shift = r / n;

        ll no_of_array = r_shift - l_shift + 1;
        ll sum = arraySum * no_of_array;

        sum -= shiftArraySum(preSum, l_shift, 0, (l % n) - 1, n);
        sum -= shiftArraySum(preSum, r_shift, (r % n) + 1, n - 1, n);

        cout << sum << endl;
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