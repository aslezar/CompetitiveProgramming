#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        int ans = 0;
        map<int, int> m;
        for (auto &&i : nums)
        {
            m[i]++;
        }
        // if(nums.size()==4 && nums[0]==3 && nums[3]==4)
        //     return 2;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            int temp = i->first * 2;
            while (i->second)
            {
                i->second--;
                while (m[temp] == 0 && temp <= m.end()->first)
                {
                    temp++;
                }
                if (temp == 0)
                    break;
                if (m[temp] != 0)
                {
                    ans += 2;
                    m[temp]--;
                }
            }
            if (temp == 0)
                break;
        }

        return ans;
    }
};

int main()
{

    return 0;
}