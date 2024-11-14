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

bool isPalindrome(const string &s)
{
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    string s;
    cin >> s;

    if (isPalindrome(s))
    {
        cout << "0\n";
        return;
    }

    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    debug(s.substr(1));
    debug(s.substr(0, n - 1));
    if (isPalindrome(s.substr(1)) && isPalindrome(s.substr(0, n - 1)))
    {
        cout << "-1\n";
        return;
    }
    cout << "1\n";
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