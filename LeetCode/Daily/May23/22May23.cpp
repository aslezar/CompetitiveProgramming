#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (auto &&i : nums)
        {
            m[i]++;
        }
        map<int, vector<int>, greater<int>> f;
        for (auto &&i : m)
        {
            f[i.second].push_back(i.first);
        }

        vector<int> ans;
        auto it = f.begin();
        while (ans.size() != k)
        {
            for (auto &&i : it->second)
            {
                if (ans.size() < k)
                    ans.push_back(i);
                else
                    break;
            }
            it++;
        }
        return ans;
    }
};
int main()
{

    return 0;
}