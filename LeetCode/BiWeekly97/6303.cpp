#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

vector<int> separateDigits(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp;
        while (nums[i] > 0)
        {
            temp.push_back(nums[i] % 10);
            nums[i] /= 10;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }
    return ans;
}

int main()
{

    return 0;
}