#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int max = INT_MIN;
        for (auto i : nums)
        {
            if (max < i)
                max = i;
        }
        return (max * k) + ((k - 1) * k / 2);
    }
};
int main()
{

    return 0;
}