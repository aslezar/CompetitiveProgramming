#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        long long ans = 0;
        while (i <= j)
        {
            if (i == j)
            {
                ans += nums[i];
                break;
            }

            vector<int> temp;
            while (nums[j] > 0)
            {
                temp.push_back(nums[j] % 10);
                nums[j] /= 10;
            }
            
            int num = nums[i];
            for (int i = temp.size() - 1; i >= 0; i--)
            {
                num = num * 10;
                num += temp[i];
            }
            cout << num << ' ';
            ans += num;
            i++;
            j--;
        }
        return ans;
    }
};