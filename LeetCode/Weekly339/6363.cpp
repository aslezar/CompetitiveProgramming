#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        map<int, int> m;
        vector<vector<int>> ans;
        int max = 0;
        for (auto &&i : nums)
        {
            m[i]++;
            if (m[i] > max)
                max = m[i];
        }
        bool flag = 1;
        while (max--)
        {
            vector<int> temp;
            for (auto &&i : m)
            {
                if (i.second != 0)
                {
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{

    return 0;
}