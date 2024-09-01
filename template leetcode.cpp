#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount
#define gcd __gcd

constexpr unsigned int mod = 1e9 + 7;
constexpr ll maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        return abs((coordinate1[0] - 'a' + coordinate1[1]) - (coordinate2[0] - 'a' + coordinate2[1])) % 2 == 0;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << s.checkTwoChessboards("a1", "b2") << endl;
    cout << endl;

    return 0;
}

#endif