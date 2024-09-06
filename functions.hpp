#include <bits/stdc++.h>
using namespace std;

// __int128_t
// constexpr float EPS = numeric_limits<float>::epsilon();
// constexpr ll INF = numeric_limits<ll>::max();

long long GCD(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long power_mod(long long base, long long exp, long long mod = 1e9 + 7)
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
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;
// safe_map<ll,int> map;

long long GCD_extended(long long a, long long b, long long &x, long long &y)
{
    x = 1, y = 0;
    long long x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        long long q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

long long LCM(long long a, long long b)
{
    return (a / GCD(a, b)) * b;
}
