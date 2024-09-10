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
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi in(n + 1);
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        in[u]++;
        in[v]++;
    }
    string s;
    cin >> s;

    char root = s[0];
    int x = 0;
    // int c[3] = {0};
    unordered_map<char, int> c;
    for (int i = 1; i < n; i++)
    {
        if (in[i + 1] == 1)
        {
            c[s[i]]++;
        }
        else
        {
            // middle node
            if (s[i] == '?')
                x++;
        }
    }

    int score = 0;

    switch (root)
    {
    case '0':
        score = c['1'];
        score += (c['?'] + 1) / 2;

        break;
    case '1':
        score = c['0'];
        score += (c['?'] + 1) / 2;
        break;
    case '?':
        score = max(c['0'], c['1']);

        if (c['0'] == c['1'])
        {
            score += (c['?'] + (x & 1)) / 2;
        }
        else
        {
            score += (c['?']) / 2;
        }
        break;

    default:
        break;
    }

    cout << score << endl;
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