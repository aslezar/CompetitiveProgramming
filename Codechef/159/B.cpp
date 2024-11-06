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

int factor_count[1000001];

void calculatePrimeFactors(int n)
{

    for (int i = 2; i <= n; ++i)
    {
        if (factor_count[i] == 0)
        { // `i` is prime
            for (int j = i; j <= n; j += i)
            {
                int num = j;
                // Count all occurrences of `i` in `j`
                while (num % i == 0)
                {
                    factor_count[j]++;
                    num /= i;
                }
            }
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll h, k;
    cin >> h >> k;

    debug(h, k);

    ll a = factor_count[h];
    ll b = floor(log2(k));

    debug(a, b);

    cout << (a + b) el;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    calculatePrimeFactors(1000000);
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}