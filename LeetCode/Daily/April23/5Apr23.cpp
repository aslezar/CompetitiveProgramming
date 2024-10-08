#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            ans = max(ans, (sum + i) / (i + 1));
        }
        return ans;
    }
};
int main()
{

    return 0;
}