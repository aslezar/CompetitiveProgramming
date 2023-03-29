#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + costs[0];

            int j = i - 1;
            while (j >= 0 && days[i - 1] - days[j] < 7)
            {
                j--;
            }
            dp[i] = min(dp[i], dp[j + 1] + costs[1]);

            j = i - 1;
            while (j >= 0 && days[i - 1] - days[j] < 30)
            {
                j--;
            }
            dp[i] = min(dp[i], dp[j + 1] + costs[2]);
        }

        return dp[n];
    }
};

int main()
{

    return 0;
}