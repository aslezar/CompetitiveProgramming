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
    void combinationSum2Helper(vector<int> &candidates, int index, int target, vii &ans, vi &cur)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        if (target < 0 || index >= candidates.size())
            return;

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                break;
            if (i == index || candidates[i] != candidates[i - 1])
            {
                cur.push_back(candidates[i]);
                combinationSum2Helper(candidates, i + 1, target - candidates[i], ans, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vii ans;
        vi cur;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, 0, target, ans, cur);
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