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
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    string s;
    cin >> s;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        string sub = s.substr(i, min(10ll, n - i));
        int mx = 0;
        for (int j = 0; j <= sub.length(); j++)
        {
            if (sub[j] != '0' && (sub[j] - '0') - j > (sub[mx] - '0') - mx)
            {
                mx = j;
            }
        }
        for (int j = mx; j > 0; j--)
        {
            swap(sub[j], sub[j - 1]);
            sub[j - 1] = sub[j - 1] - '0' - 1 + '0';
        }
        for (int j = 0; j < sub.length(); j++)
        {
            s[i + j] = sub[j];
        }
    }
    cout << s el
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