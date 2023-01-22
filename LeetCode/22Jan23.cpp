// 491. Non-decreasing Subsequences
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define el << '\n'

bool isPalindrome(string &s, int l, int h)
{
    while (l < h)
    {
        if (s[l++] != s[h--])
            return false;
    }
    return true;
}
void backtrack(string &nums, vector<string> &seq, vector<vector<string>> &result, int index)
{
    if (index >= nums.length())
    {
        result.push_back(seq);
    }
    for (int end = index; end < nums.size(); end++)
    {
        if (isPalindrome(nums, index, end))
        {
            seq.push_back(nums.substr(index, end - index + 1));
            backtrack(nums, seq, result, end + 1);
            seq.pop_back();
        }
    }

    // if (seq.empty() || seq.back().back() == nums[index])
    // {
    //     seq.back().push_back(nums[index]);
    //     backtrack(nums, seq, result, index + 1);
    //     seq.pop_back();
    // }
    // backtrack(nums, seq, result, index + 1);
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> seq;
    backtrack(s, seq, ans, 0);

    return ans;
}
int main()
{
    string nums = "aab";
    vector<vector<string>> ans(partition(nums));
    for (int i = 0; i < ans.size(); i++)
    {
        cout << '[';

        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ',';
        cout << '\b' << ']' << '\n';
    }
    return 0;
}
