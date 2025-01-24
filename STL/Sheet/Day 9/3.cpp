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
    void combinationSumHelper(vector<int> &candidates, int index, int target, vi &cur, vii &ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        if (target < 0)
        {
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                cur.push_back(candidates[i]);
                combinationSumHelper(candidates, i, target - candidates[i], cur, ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vii ans;
        vi cur;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, 0, target, cur, ans);
        return ans;
    }
};

class Solution2
{
public:
    void combinationSumHelper(vector<int> &candidates, int index, int target,
                              vi &cur, vii &ans)
    {
        if (target == 0)
        {
            ans.push_back(cur); // O(n)
            return;
        }

        if (target < 0 || index >= candidates.size())
        {
            return;
        }

        // not pick
        combinationSumHelper(candidates, index + 1, target, cur, ans);
        // pick
        cur.push_back(candidates[index]);
        combinationSumHelper(candidates, index, target - candidates[index], cur, ans);
        cur.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vii ans;
        vi cur;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, 0, target, cur, ans);
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