#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        vector<int> ans;
        map<int, int> num;
        for (size_t i = 0; i < k; i++)
        {
            num[nums[i]]++;
        }
        int c = 0;
        for (auto &&i : num)
        {
            c += i.second;
            if (c >= x)
            {
                ans.push_back(i.first < 0 ? i.first : 0);
                break;
            }
        }

        for (size_t i = k; i < nums.size(); i++)
        {
            num[nums[i - k]]--;
            num[nums[i]]++;
            int c = 0;
            for (auto &&i : num)
            {
                c += i.second;
                if (c >= x)
                {
                    ans.push_back(i.first < 0 ? i.first : 0);
                    break;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}