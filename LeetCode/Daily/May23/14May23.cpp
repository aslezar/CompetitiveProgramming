#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int backtrack(vector<int> &nums, int mask, int pairsPicked, vector<int> &memo)
    {
        if (2 * pairsPicked == nums.size())
        {
            return 0;
        }

        if (memo[mask] != -1)
        {
            return memo[mask];
        }

        int maxScore = 0;

        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex)
        {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex)
            {

                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1)
                {
                    continue;
                }

                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));

                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);

                maxScore = max(maxScore, currScore + remainingScore);
            }
        }

        memo[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int> &nums)
    {
        int memoSize = 1 << nums.size(); // 2^(nums array size)
        vector<int> memo(memoSize, -1);
        return backtrack(nums, 0, 0, memo);
    }
};
int main()
{

    return 0;
}