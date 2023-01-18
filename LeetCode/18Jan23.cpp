// 918. Maximum Sum Circular Subarray
#include <iostream>
#include <vector>
using namespace std;

#define el cout << '\n';
int maxSubarraySumCircular(vector<int> &nums)
{
    // vector<int> presum;
    // presum.push_back(nums[0]);
    // for(int i=1;i< nums.size();i++)
    // {
    //     presum.push_back(presum.back()+nums[i]);
    // }
    // for(int i=0;i< presum.size();i++)
    // {
    //     cout<<presum[i]<<' ';
    // }
    // cout<<'\n';
    int localmax = nums[0];
    int ans = -32165;
    for (int i = 1; i < nums.size(); i++)
    {
        localmax = max(nums[i], nums[i] + localmax);
        ans = max(ans, localmax);
        // ans=max(ans,localmax=max(nums[i],nums[i]+localmax));
    }
    return ans;
}
int main()
{
    vector<int> nums({1, -2, 3, -2});
    cout << maxSubarraySumCircular(nums);
    return 0;
}
