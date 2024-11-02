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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi p(n, -1);

    p[1] = 0;

    int m = 2;
    while (m < n - 1)
    {
        int t;
        cout << "? " << 1 << ' ' << m << endl;
        cin >> t;
        if (t == -1)
            exit(0);

        if (t == 1)
        {
            p[m] = 0;
            m++;
        }
        else
        {
            break;
        }
    }

    p[m] = 1;

    set<int> tent;
    for (int i = 2; i <= m; i++)
    {
        tent.insert(i);
    }

    for (int j = m + 1; j < n; j++)
    {
        int breakpoint = -1;
        for (auto &i : tent)
        {
            cout << "? " << i << ' ' << j << endl;
            int t = 0;
            cin >> t;
            if (t == -1)
                exit(0);
            if (t == 0)
            {
                p[j] = i;
                breakpoint = i;
                break;
            }
        }
        // remove tent from starting to till breakpoint
        tent.erase(tent.begin(), next(tent.find(breakpoint)));
        tent.insert(j);
    }

    cout << "! ";
    for (auto &i : p)
    {
        if (i == -1)
            continue;
        cout << i ws;
    }
    cout << endl;
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