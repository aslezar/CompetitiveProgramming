#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

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

class Solution
{
    vector<int> fact;

    long long nCr(int n, int r)
    {
        return (fact[n] * power_mod(fact[r], mod - 2) % mod * power_mod(fact[n - r], mod - 2) % mod) % mod;
    }

public:
    int numberOfWays(int n, int x, int y)
    { // fact upto 1000
        fact.push_back(1);
        for (long long i = 1; i <= 1000; i++)
        {
            fact.push_back((fact.back() * i) % mod);
        }
        long long ans = 0;

        for (int i = 1; i <= x; i++)
        {
            if (i > n)
                break;
            long long comb = 0;

            // using inclusion-exclusion principle
            for (int c = 0; c < i; c++)
            {
                long long no = (nCr(i, c) * power_mod(i - c, n)) % mod;
                debug(i, c, no);
                if (c % 2 == 0)
                    comb = (comb + no) % mod;
                else
                    comb = (comb - no + mod) % mod;
            }
            comb = (comb * nCr(x, i)) % mod;

            comb = (comb * power_mod(y, i)) % mod;
            debug(comb);
            ans = (ans + comb) % mod;
        }
        return ans;
    }
};