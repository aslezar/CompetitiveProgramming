// 57. Insert Interval
#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'

vector<vector<int>> insertfn(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            newInterval = intervals[i];
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}
int main()
{
    vector<vector<int>> intervals({{1, 3}, {6, 9}});
    vector<int> newinterval({2, 5});
    vector<vector<int>> ans(insertfn(intervals, newinterval));
    for (int i = 0; i < ans.size(); i++)
    {
        cout << '[' << ans[i][0] << ',' << ans[i][1] << ']' << '\n';
    }
    return 0;
}