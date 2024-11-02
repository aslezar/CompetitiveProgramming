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

    string s;
    cin >> s;

    debug(s);

    int ava = 0;
    int cost = 0;

    set<int> zero, one;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero.insert(i);
        else
            one.insert(i);
    }

    // reverse it for one
    for (auto i = one.rbegin(); i != one.rend(); i++)
    {
        auto it = zero.lower_bound(*i);
        if (it == zero.begin())
        {
            auto it2 = one.begin();
            // debug(*i, *it, *it2);
            if (*it2 < *i)
            {
                cost += (*it2 + 1);
                one.erase(it2);
            }
            else
                cost += (*i + 1);
        }
        else
        {
            it--;
            cost += (*it + 1);
            zero.erase(it);
        }
    }

    for (auto &i : zero)
    {
        cost += (i + 1);
    }
    cout << cost el;
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