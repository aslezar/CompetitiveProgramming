#include <set>
#include <vector>
using namespace std;
class SummaryRanges
{
    set<int> values;

public:
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        values.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        if (values.empty())
        {
            return {{}};
        }
        vector<vector<int>> ans;
        int left = -1, right = -1;
        for (auto &&i : values)
        {
            if (left < 0)
            {
                left = right = i;
            }
            else if (i == right + 1)
            {
                right++;
            }
            else
            {
                if (left >= 0)
                    ans.push_back({left, right});
                left = right = i;
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};
