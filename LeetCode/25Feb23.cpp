#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, buy = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            if (ans < prices[i] - buy)
                ans = prices[i] - buy;
        }

        if (ans < 0)
            ans = 0;
        return ans;
    }
};

int main()
{

    return 0;
}