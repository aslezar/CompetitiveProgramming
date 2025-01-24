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
    void subsetSumsHelper(vector<int> &arr, int index, vi &ans, int curSum)
    {
        if (index >= arr.size())
        {
            ans.push_back(curSum);
            return;
        }

        // skip this ele
        subsetSumsHelper(arr, index + 1, ans, curSum);

        // pick this ele
        subsetSumsHelper(arr, index + 1, ans, curSum + arr[index]);
    }
    vector<int> subsetSums(vector<int> &arr)
    {
        vector<int> ans;
        subsetSumsHelper(arr, 0, ans, 0);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif