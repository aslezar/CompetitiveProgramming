#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minImpossibleOR(vector<int> &nums)
    {
        int ans = 0;
        int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
        for (int i = 0; i < 32; i++)
        {
            int j = 0;
            for (j = 0; j < nums.size(); j++)
            {
                if (nums[j] == a[i])
                    break;
            }
            if (j == nums.size())
                return a[i];
        }
        return ans;
    }
};

int main()
{

    return 0;
}