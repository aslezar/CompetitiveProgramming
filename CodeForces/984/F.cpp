#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int unsigned long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef unsigned long long ll;

int xorTill(int n)
{
    int r = n % 4;
    switch (r)
    {
    case 0:
        return n;
        break;

    case 1:
        return 1;
        break;

    case 2:
        return n + 1;
        break;

    case 3:
        return 0;
        break;
    }
    return 0;
}

void solve([[maybe_unused]] ll &_case_no)
{
    // (1≤l≤r≤1018, 0≤i≤30, 0≤k<2i)
    ll l, r, i, k;
    cin >> l >> r >> i >> k;

    // debug(l, r, i, k);

    // int ans = helper(r, i, k) ^ helper(l - 1, i, k);

    int ans = xorTill(r) ^ xorTill(l - 1);
    // debug(ans);

    int m = 1LL << i;

    k %= m;

    // debug((r - k + m) / (m * 1.0));
    int n1 = ceil((l - k + m) / (m * 1.0L));
    int n2 = floor((r - k + m) / (m * 1.0L));
    // debug(n1, n2);

    int cnt = n2 - n1 + 1;
    // debug(cnt);

    int v1 = k + (n1 - 1) * m;
    int v2 = k + (n2 - 1) * m;

    // debug(v1, v2);

    v1 = v1 >> i;
    v2 = v2 >> i;

    // debug(v1, v2);

    int x = xorTill(v1 - 1) ^ xorTill(v2);
    // debug(x);
    x = x << i;
    // debug(x);
    if (cnt & 1)
        x += k;
    // debug(x);

    bitset<64> binary(v1);
    // debug(binary);

    ans ^= x;

    cout << ans el;
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