#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution
{
public:
    int merge_size(vector<pii> &intervals)
    {
        vector<pii> merged;
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end());
        pii current_interval = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].first < current_interval.second)
            {
                current_interval.second = max(current_interval.second, intervals[i].second);
            }
            else
            {
                merged.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        merged.push_back(current_interval);
        return merged.size();
    }
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<pii> x, y;
        for (int i = 0; i < rectangles.size(); i++)
        {
            x.push_back({rectangles[i][1], rectangles[i][3]});
            y.push_back({rectangles[i][0], rectangles[i][2]});
        }
        sorta(x);
        sorta(y);

        debug(x);
        debug(y);

        int xx = merge_size(x);
        debug(xx);
        if (xx >= 3)
            return true;

        int yy = merge_size(y);
        debug(yy);
        if (yy >= 3)
            return true;

        return false;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

    vii grid = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
    cout << s.checkValidCuts(5, grid) << '\n';

    cout << '\n';

    return 0;
}

#endif