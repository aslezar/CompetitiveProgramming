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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0, d = 0, k = 0;
    cin >> n >> d >> k;

    vector<int> overlap(n + 2, 0);
    d--;

    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        overlap[max(1ll, l - d)]++;
        overlap[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        overlap[i] += overlap[i - 1];
    }

    // debug(overlap);

    auto mx = max_element(overlap.begin() + 1, overlap.end() - d - 1);
    auto mn = min_element(overlap.begin() + 1, overlap.end() - d - 1);

    cout << (mx - overlap.begin()) << " " << (mn - overlap.begin()) << '\n';
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