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
    int ans;
    int maxRemovalsHelper(string &source, string &pattern, vector<int> &targetIndices, int index)
    {
        if (index == targetIndices.size())
            return 0;

        // do not remove this index
        int curAns = maxRemovalsHelper(source, pattern, targetIndices, index + 1);

        // remove this index

        return curAns;
    }

public:
    int maxRemovals(string source, string pattern, vector<int> &targetIndices)
    {
        ans = 0;
        maxRemovalsHelper(source, pattern, targetIndices, 0);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
    // Output: 1

    string source = "abbaa";
    string pattern = "aba";
    vector<int> targetIndices = {0, 1, 2};
    cout << s.maxRemovals(source, pattern, targetIndices) << '\n';

    cout << '\n';

    return 0;
}

#endif