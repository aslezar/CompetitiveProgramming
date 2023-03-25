#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int start = 0, minfound = 0, maxfound = 0;
        bool ismax = 0, ismin = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                ismax = 0;
                ismin = 0;
                start = i + 1;
            }
            if (nums[i] == minK)
            {
                ismin = 1;
                minfound = i;
            }
            if (nums[i] == maxK)
            {
                ismax = 1;
                maxfound = i;
            }
            if (ismax && ismin)
                ans += (min(minfound, maxfound) - start + 1);
        }
        return ans;
    }
};
int main()
{

    return 0;
}