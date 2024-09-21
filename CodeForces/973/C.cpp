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

bool ask(string str)
{
    cout << "? " + str << endl;
    int res0;
    cin >> res0;
    if (res0 == 1)
    {
        return true;
    }
    return false;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    string ans;

    bool res = ask("0");
    if (res == 1)
        ans = "0";
    else
    {
        ans = string(n, '1');
        cout << "! " << ans << endl;
        return;
    }

    while (true)
    {
        if (ans.size() == n)
            break;
        assert(ans.size() < n);

        bool res0 = ask(ans + "0");
        if (res0 == 1)
        {
            ans += "0";
            if (ans.size() == n)
                break;
            continue;
        }
        bool res1 = ask(ans + "1");
        if (res1 == 1)
        {
            ans += "1";
            if (ans.size() == n)
                break;
            continue;
        }
        break;
    }
    while (true)
    {
        if (ans.size() == n)
            break;
        assert(ans.size() < n);

        // cout << "? 1" + ans << endl;
        bool res1 = ask("1" + ans);
        if (res1 == 1)
        {
            ans = "1" + ans;
            if (ans.size() == n)
                break;
            continue;
        }

        // cout << "? 0" + ans << endl;
        bool res0 = ask("0" + ans);
        if (res0 == 1)
        {
            ans = "0" + ans;
            if (ans.size() == n)
                break;
            continue;
        }
        break;
    }

    cout << "! " << ans << endl;
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