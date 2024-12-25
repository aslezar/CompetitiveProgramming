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

void precalculateFactorizations(int n, vector<unordered_map<int, int>> &factorizations)
{
    vector<int> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            factorizations[i][i] = 1;
            for (int j = i + i; j <= n; j += i)
            {
                isPrime[j] = false;
                int cnt = 0;
                int k = j;
                while (k % i == 0)
                {
                    k /= i;
                    cnt++;
                }
                factorizations[j][i] = cnt;
            }
        }
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n = 0;
    cin >> n;

    int m = 0;
    cin >> m;

    vi v(n);
    input(v, n);

    int mx = *max_element(all(v));

    vector<unordered_map<int, int>> factorizations(mx + 1);
    precalculateFactorizations(mx, factorizations);

    unordered_map<int, int> fOfM;
    for (int i = 2; i <= m; i++)
    {
        for (auto [prime, count] : factorizations[i])
        {
            fOfM[prime] += count;
        }
    }
    debug(fOfM);

    for (int i = 0; i < n; i++)
    {
        if (v[i] != 1)
            for (auto [prime, count] : factorizations[v[i]])
            {
                fOfM[prime] += count;
            }

        int cnt = 1;
        for (auto [prime, count] : fOfM)
        {
            cnt = (cnt * (count + 1)) % mod;
        }
        cout << cnt << ' ';

        if (v[i] != 1)
            for (auto [prime, count] : factorizations[v[i]])
            {
                fOfM[prime] -= count;
            }
    }
    cout el
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}