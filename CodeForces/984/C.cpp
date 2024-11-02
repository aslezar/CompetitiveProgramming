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

bool isExist(int i, string &s)
{
    if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
    {
        return true;
    }
    return false;
}

void solve([[maybe_unused]] ll &_case_no)
{
    string s;
    cin >> s;

    int n = s.length();
    // vi v(n, 0);
    set<int> e;

    for (int i = 0; i < n - 3; i++)
    {
        if (isExist(i, s))
        {
            e.insert(i);
        }
    }

    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++)
    {
        ll i;
        char v;
        cin >> i >> v;
        s[i - 1] = v;
        for (int j = max(0ll, i - 4); j < i; j++)
        {
            if (isExist(j, s))
            {
                e.insert(j);
            }
            else
            {
                e.erase(j);
            }
        }
        if (e.size() > 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
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