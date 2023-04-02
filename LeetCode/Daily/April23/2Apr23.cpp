#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);
        for (int i = 0; i < spells.size(); i++)
        {
            long long temp = ceil((1.0 * success) / spells[i]);
            if (potions[potions.size() - 1] < temp)
                ans[i] = 0;
            else
                ans[i] = (potions.end() - (lower_bound(potions.begin(), potions.end(), temp)));
        }
        return ans;
    }
};
int main()
{
    return 0;
}