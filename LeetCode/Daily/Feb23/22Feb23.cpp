#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    bool feasible(vector<int> &wg, int c, int day)
    {
        int ans = 1, load = 0;
        for (int weight : wg)
        {
            load += weight;
            if (load > c)
            {
                ans++;
                load = weight;
            }
        }

        return ans <= day;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int tload = 0, maxLoad = 0;
        for (int weight : weights)
        {
            tload += weight;
            maxLoad = max(maxLoad, weight);
        }

        int l = maxLoad, r = tload;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (feasible(weights, mid, days))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{

    return 0;
}