#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int ans = 0;
        for (auto &&i : nums)
        {
            if (i == 0)
                return 0;
            if (i < 0)
                ans++;
        }
        return ans & 1 ? -1 : 1;
    }
};
int main()
{

    return 0;
}