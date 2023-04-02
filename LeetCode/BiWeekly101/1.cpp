#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (auto &&i : nums1)
        {
            for (auto &&j : nums2)
            {
                if (i == j)
                    return i;
            }
        }
        return min(nums1[0], nums2[0]) * 10 + max(nums1[0], nums2[0]);
    }
};
int main()
{

    return 0;
}