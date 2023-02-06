#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[i + n]);
    }
    return ans;
}
int main()
{
    vector<int> v = {2, 5, 1, 3, 4, 7};
    shuffle(v, 3);
    return 0;
}