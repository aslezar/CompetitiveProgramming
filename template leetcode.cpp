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

class Solution
{
public:
    bool checkTwoChessboards(string a)
    {
        return 0;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << s.checkTwoChessboards("a1");
    cout << '\n';

    return 0;
}

#endif