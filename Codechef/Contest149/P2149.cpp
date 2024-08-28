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
    ll a, b, x;
    cin >> a >> b >> x;

    int area = x * x;
    int cost = 0;
    if (area < a * b)
    {
        if (a > b)
        {
            a = 1;
        }
        else
        {
            b = 1;
        }
        cost++;
    }
    if (area < a * b)
    {
        if (a > b)
        {
            a = 1;
        }
        else
        {
            b = 1;
        }
        cost++;
    }
    cout << cost << endl;
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