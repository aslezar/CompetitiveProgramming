#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> a(nums1.begin(), nums1.end());
        unordered_set<int> b(nums2.begin(), nums2.end());
        for (auto &&i : a)
        {
            if (b.find(i) == b.end())
                temp.push_back(i);
        }
        ans.push_back(temp);
        temp.clear();
        for (auto &&i : b)
        {
            if (a.find(i) == a.end())
                temp.push_back(i);
        }
        ans.push_back(temp);
        return ans;
    }
};

int main()
{

    return 0;
}