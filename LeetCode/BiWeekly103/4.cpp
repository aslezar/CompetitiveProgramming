#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            if (i == nums.size())
                i = 0;
            if (nums[i] == INT_MIN)
            {
                i++;
                continue;
            }
            if (nums[i] == sorted[j])
            {
                nums[i] = INT_MIN;
                j++;
            }
            i++;
            ans++;
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {1, 2, 4, 3};
    Solution t;
    cout << t.countOperationsToEmptyArray(a);

    return 0;
}