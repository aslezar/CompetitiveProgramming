#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution2
{
public:
    string getPermutation(int n, int k)
    {
        string s;
        for (int i = 1; i <= n; i++)
        {
            s += (i + '0');
        }
        for (int i = 1; i <= k; i++)
        {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        k -= 1;
        vi fact(10, 1);
        fact[0] = 1;
        for (int i = 1; i <= 9; i++)
        {
            fact[i] = i * fact[i - 1];
        }
        vector<char> v;
        string s;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i + '0');
        }
        for (int i = 0; i < n; i++)
        {
            int b = k / (fact[n - i - 1]);
            debug(b, k);
            k = k % (fact[n - i - 1]);
            s += v[b];
            v.erase(v.begin() + b);
        }
        debug(s);
        return s;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    s.getPermutation(4, 9);

    cout << '\n';

    return 0;
}

#endif