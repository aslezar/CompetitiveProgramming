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

vi s;
void precompute()
{
    for (int i = 1; i <= log2(1e9); i++)
    {
        int no = (1 << i) - 1;
        int n = 0;
        while (n <= 1e9)
        {
            if (n & 1)
            {
                n = n << i;
            }
            else
            {
                n = n << i;
                n += no;
            }
            s.push_back(n);
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    int l = 0, r = 0;
    cin >> l >> r;
    

    int rr = upper_bound(all(s), r) - s.begin();

    int ll = upper_bound(all(s), l-1) - s.begin();

    cout << rr - ll el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    precompute();
    sorta(s);
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}