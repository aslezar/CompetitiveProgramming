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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << 0 el;
        return;
    }
    if (s[0] != t[0])
    {
        cout << -1 el;
        return;
    }
    if (s.length() < t.length())
    {
        swap(s, t);
    }
    assert(s.length() >= t.length());

    int index = 0;
    while (index < t.length() && s[index] == t[index])
    {
        index++;
    }
    if (index == t.length())
    {
        cout << 1 el;
        return;
    }
    string s1 = s.substr(index + 1);
    string s2 = t.substr(index);

    reverse(all(s1));
    reverse(all(s2));
    if (s1.find(s2) == 0)
    {
        cout << 1 el;
        return;
    }

    cout << 2 el;
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