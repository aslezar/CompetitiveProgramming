// 974. Subarray Sums Divisible by K
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define el << '\n'';
int subarraysDivByK(vector<int>& nums, int k) {
            vector<int> prefix(k,0);
            prefix[0]=1;
            int sum=0;
            int modsum=0;
            for(int i=0;i<nums.size();i++)
            {
                modsum=(modsum+nums[i]%k +k)%k;
                sum+=prefix[modsum];
                prefix[modsum]++;
            }
            return sum;
        }
int main()
{
    vector<int> nums({4,5,0,-2,-3,1});
    cout << subarraysDivByK(nums,5);
    return 0;
}
