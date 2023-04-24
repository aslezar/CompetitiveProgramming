#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int c1 = 0;
        for (auto &&i : nums)
            if (i == 1)
                c1++;
        if (c1)
            return nums.size() - c1;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (__gcd(nums[i], nums[i + 1]) == 1)
                return nums.size();
        }
        int temp = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            temp = __gcd(temp, nums[i]);
        }
        if (temp != 1)
            return -1;
        return nums.size() + 1;
    }
};

int main()
{

    return 0;
}