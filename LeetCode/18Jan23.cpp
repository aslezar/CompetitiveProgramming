// 918. Maximum Sum Circular Subarray
#include <iostream>
#include <vector>
#include <climits>
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
    int localmaxsum = 0;
    int localminsum = 0;
    int totalsum = 0;
    int gmaxsum = INT_MIN;
    int gminsum = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        totalsum += nums[i];

        // localmaxsum = max(nums[i], nums[i] + localmaxsum);
        // gmaxsum = max(gmaxsum, localmaxsum);
        gmaxsum = max(gmaxsum, localmaxsum = max(nums[i], nums[i] + localmaxsum));

        // cout << localmaxsum << ' ' << gmaxsum << ' ' << nums[i] << '\n';

        // localminsum = min(nums[i], nums[i] + localminsum);
        // gminsum = min(gminsum, localminsum);
        gminsum = min(gminsum, localminsum = min(nums[i], nums[i] + localminsum));
    }
    return (totalsum == gminsum) ? gmaxsum : max(gmaxsum, totalsum - gminsum);
}
int main()
{
    vector<int> nums({1, -2, 3, -2});
    cout << maxSubarraySumCircular(nums);
    return 0;
}
