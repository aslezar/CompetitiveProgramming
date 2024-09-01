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
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    // debug(n,s);

    if (n % 2 == 0)
    {
        vi fOdd(26, 0), fEven(26, 0);
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                fOdd[s[i] - 'a']++;
            }
            else
            {
                fEven[s[i] - 'a']++;
            }
        }
        sortd(fOdd);
        sortd(fEven);
        cout << ((n / 2 - fOdd[0]) + (n / 2 - fEven[0])) << endl;
    }
    else
    {
        int ans = INT_MAX;
        vi left_odd(26, 0);
        vi left_even(26, 0);
        vi right_odd(26, 0);
        vi right_even(26, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i & 1)
                right_odd[s[i] - 'a']++;
            else
                right_even[s[i] - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            // remove freq
            if (i & 1)
                right_odd[s[i] - 'a']--;
            else
                right_even[s[i] - 'a']--;

            vi fOdd(26, 0), fEven(26, 0);

            // if (s[i] == 'b')
            // {
            //     debug(left_odd);
            //     debug(left_even);
            //     debug(right_odd);
            //     debug(right_even);
            // }
            for (int i = 0; i < 26; i++)
            {
                fOdd[i] = left_odd[i] + right_even[i];
                fEven[i] = left_even[i] + right_odd[i];
            }
            // if (s[i] == 'b')
            // {
            //     debug(fOdd);
            //     debug(fEven);
            // }

            sortd(fOdd);
            sortd(fEven);
            ll curAns = ((n / 2 - fOdd[0]) + (n / 2 - fEven[0]));
            // debug(s[i], curAns);
            // debug(fOdd);
            // debug(fEven);
            ans = min(ans, curAns);

            if (ans == 0)
                break;

            if (i & 1)
                left_odd[s[i] - 'a']++;
            else
                left_even[s[i] - 'a']++;
        }
        cout << ans + 1 << endl;
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