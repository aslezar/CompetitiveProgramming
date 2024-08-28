#include <bits/stdc++.h>
using namespace std;

#define ll long long
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

long long power_mod(long long base, long long exp, long long mod = mod)
{
    // this function multiplies a number by itself n times in O(logn)
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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// unordered_map<ll, int, custom_hash> safe_map;

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cost = 0;
    int i = 0;
    while (i < n && a[i] <= 0)
        i++;

    int j = n - 1;
    while (j >= 0 && a[j] <= 0)
        j--;
    for (int k = i; k <= j; k++)
    {
        if (a[k] < 0)
        {
            cost++;
        }
    }
    cout << cost << '\n';
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}