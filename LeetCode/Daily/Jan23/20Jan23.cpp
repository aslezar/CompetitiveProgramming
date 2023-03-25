// 491. Non-decreasing Subsequences
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define el << '\n'
void backtrack(vector<int> &nums, vector<int> &seq, set<vector<int>> &result, int index)
{
    if (index >= nums.size())
    {
        if (seq.size() > 1)
        {
            result.insert(seq);
        }
        return;
    }
    if (seq.empty() || seq.back() <= nums[index])
    {
        seq.push_back(nums[index]);
        backtrack(nums, seq, result, index + 1);
        seq.pop_back();
    }
    backtrack(nums, seq, result, index + 1);
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{

    set<vector<int>> ans;
    vector<int> seq;
    backtrack(nums, seq, ans, 0);

    return vector(ans.begin(), ans.end());
}
int main()
{
    vector<int> nums({4, 6, 7, 7});
    vector<vector<int>> ans(findSubsequences(nums));
    for (int i = 0; i < ans.size(); i++)
    {
        cout << '[';

        for (int j = 0; j < ans[i].size(); j++)

            cout << ans[i][j] << ',';
        cout << '\b' << ']' << '\n';
    }
    return 0;
}
