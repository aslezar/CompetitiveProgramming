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

int helper(int mn, string &s, int k, int n, int m)
{
    int alice = 0;
    int aTurn = 0, bTurn = 0;
    for (int i = 0; i < mn; i++)
    {
        char c = s[i % k];
        if (c == 'A')
        {
            alice += ((4 * bTurn) + (n - i) + (m - i - 1));
            aTurn++;
        }
        else
        {
            alice -= ((4 * aTurn) + (n - i) + (m - i - 1));
            bTurn++;
        }
    }
    return alice;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    int mn = min(n, m);
    int mx = max(n, m);

    int times = mn / k;
    int left = mn % k;

    int aCount = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'A')
        {
            aCount++;
        }
    }

    int alice = 0;
    int aTurn = 0, bTurn = 0;

    int scoreInK = helper(k, s, k, k, k);
    // int a = alice;

    for (int i = 0; i < times; i++)
    {
        alice += (scoreInK + ((aTurn - bTurn) * 2));
        aTurn += aCount;
        bTurn += (k - aCount);
    }

    debug(alice, aTurn, bTurn);

    for (int i = 0; i < left; i++)
    {
        char c = s[i % k];
        if (c == 'A')
        {
            alice += ((4 * bTurn) + 1);
            aTurn++;
        }
        else
        {
            alice -= ((4 * aTurn) + 1);
            bTurn++;
        }
        debug(alice, aTurn, bTurn);
    }

    alice += ((aTurn - bTurn) * (mx - mn));
    debug(alice, aTurn, bTurn);

    if (alice > 0)
    {
        cout << "Alice" el;
        return;
    }
    else if (alice < 0)
    {
        cout << "Bob" el;
        return;
    }
    else
    {
        cout << "Draw" el;
        return;
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