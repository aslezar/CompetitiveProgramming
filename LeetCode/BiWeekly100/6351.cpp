#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long score = 0;
        vector<bool> v(nums.size() + 1, 0);
        map<int, vector<int>> m;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        for (auto &&number : m)
        {
            for (auto &&index : number.second)
            {
                if (v[index] == 0)
                {
                    score += number.first;
                    v[index] = 1;
                    v[index + 1] = 1;
                    if (index != 0)
                        v[index - 1] = 1;
                }
            }
        }
        return score;
    }
};

int main()
{

    return 0;
}