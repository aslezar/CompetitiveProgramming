#include <vector>
#include <math.h>

class Solution
{
public:
    double timeReq(vector<int> &dist, int speed)
    {
        double time = 0.0;
        for (int i = 0; i < dist.size(); i++)
        {
            time += ceil((double)dist[i] / (double)speed);
        }
        time -= ceil((double)dist[dist.size() - 1] / (double)speed);
        time += (double)dist[dist.size() - 1] / (double)speed;
        return time;
    }
    int minSpeedOnTime(vector<int> &dist, double hour,int l=1,int r=1e7,int speed=-1)
    {
        if(l>r) return speed;
        int m = l + (r - l) / 2;
        if (timeReq(dist, m) <= hour)
            return minSpeedOnTime(dist,hour,l,m-1,m);
        return minSpeedOnTime(dist,hour,m+1,r,speed);
    }
    // int minSpeedOnTime(vector<int> &dist, double hour)
    // {
    //     int l = 1, r = 1e7;
    //     int speed = -1;
    //     while (l <= r)
    //     {
    //         int m = l + (r - l) / 2;
    //         if (timeReq(dist, m) <= hour)
    //         {
    //             speed = m;
    //             r = m - 1;
    //         }
    //         else
    //         {
    //             l = m + 1;
    //         }
    //     }
    //     return speed;
    // }
};