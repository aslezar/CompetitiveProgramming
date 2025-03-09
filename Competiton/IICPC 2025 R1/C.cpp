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
    int q = 0;
    cin >> n >> q;

    vi v(n);
    input(v, n);

    vii cnt(n + 1);

    cnt[0] = vi(11, 0);

    for (int i = 0; i < n; i++)
    {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][v[i]]++;
    }
    debug(cnt);

    for (int qq = 0; qq < q; qq++)
    {
        int k, l, r;
        cin >> k >> l >> r;
        l--;
        r--;

        // update

        auto comp = [&](const vi &a, const vi &b) -> bool {

        };  

        sort(all(cnt), comp);

        int c = 0;
        for (int i = 1; i <= 100; i++)
        {
            c += (cnt[r + 1][i] - cnt[l][i]);
            if (c > (r - l) / 2)
            {
                debug(c);
                cout << i << '\n';
                break;
            }
        }
    }
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    // cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}