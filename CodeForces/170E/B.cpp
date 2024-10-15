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

long long power_mod(long long base, long long exp, long long mod = 1e9 + 7)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    debug(t);
    vector<int> N(t);
    vector<int> K(t);
    for (ll i = 0; i < t; i++)
    {
        cin >> N[i];
    }
    for (ll i = 0; i < t; i++)
    {
        cin >> K[i];
    }
    // int maxN = *max_element(all(N));
    // debug(maxN);
    // vector<vector<int>> C(maxN + 1);
    // for (int i = 1; i <= maxN; i++)
    // {
    //     C[i].push_back(1);
    //     for (int k = 1; k < i; k++)
    //     {
    //         C[i].push_back((C[i].back() + C[i - 1][k - 1]) % mod);
    //     }
    //     C[i].push_back(1);
    // }
    // debug(C);
    for (int i = 0; i < t; i++)
    {
        cout << power_mod(2, K[i]) el;
    }
    return 0;
}