#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int size = piles.size();
        if (size == h)
        {
            int max = 0;
            for (int i = 0; i < size; i++)
                if (max < piles[i])
                    max = piles[i];
            return max;
        }
        int ans = -1;
        int l = 1, r = 1e9;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            long long hrs = 0;
            for (int i = 0; i < size; i++)
                hrs += ((piles[i] + mid - 1) / mid);
            if (hrs <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
int main()
{
    return 0;
}