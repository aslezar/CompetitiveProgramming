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
constexpr unsigned int mod = 998244353;

long long power_mod(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n, q;
    cin >> n >> q;

    vi a(n), b(n);
    input(a, n);
    input(b, n);

    vi aa = a, bb = b;
    sorta(a);
    sorta(b);

    map<int, multiset<int>> ma, mb;
    for (int i = 0; i < n; i++)
    {
        ma[a[i]].insert(b[i]);
        mb[b[i]].insert(a[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * min(a[i], b[i])) % mod;
    }
    cout << ans << ' ';

    for (int qq = 0; qq < q; qq++)
    {
        int o, x;
        cin >> o >> x;

        if (o == 1)
        {
            int &no = aa[x - 1];
            int last = *ma[no].rbegin();
            ma[no].erase(prev(ma[no].end()));

            auto it = mb[last].find(no);
            assert(it != mb[last].end());
            mb[last].erase(it);

            ans = (ans * power_mod(min(no, last), mod - 2)) % mod;

            no++;

            ma[no].insert(last);
            mb[last].insert(no);

            ans = (ans * min(no, last)) % mod;
        }
        else
        {
            int &no = bb[x - 1];
            int last = *mb[no].rbegin();
            mb[no].erase(prev(mb[no].end()));

            auto it = ma[last].find(no);
            assert(it != ma[last].end());
            ma[last].erase(it);

            ans = (ans * power_mod(min(no, last), mod - 2)) % mod;

            no++;

            mb[no].insert(last);
            ma[last].insert(no);

            ans = (ans * min(no, last)) % mod;
        }
        cout << ans << ' ';
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
