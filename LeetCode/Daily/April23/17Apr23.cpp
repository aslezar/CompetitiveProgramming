#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max = 0;
        for (auto &&i : candies)
            if (i > max)
                max = i;
        vector<bool> ans;
        for (auto &&i : candies)
        {
            if (i + extraCandies > max)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
int main()
{

    return 0;
}