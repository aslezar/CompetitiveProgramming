#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    long long tripcompleted(vector<int> &times, long long &time)
    {
        long long ans = 0;
        for (int i = 0; i < times.size(); i++)
            ans += (time / times[i]);
        return ans;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long ans = -1;
        long long l = 0, r = 1e14 + 10;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long trips = tripcompleted(time, mid);
            if (trips >= totalTrips)
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