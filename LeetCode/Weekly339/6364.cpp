#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

bool mycomparer(std::pair<int, int> lhs, std::pair<int, int> rhs)
{
    return lhs.second - lhs.first < rhs.second - rhs.first;
}
class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int ans = 0;
        vector<pair<int, int>> reward;
        for (int i = 0; i < reward1.size(); i++)
            reward.push_back({reward1[i], reward2[i]});
        sort(reward.begin(), reward.end(), mycomparer);
        for (size_t i = 0; i < k; i++)
            ans += reward[i].first;
        for (size_t i = k; i < reward.size(); i++)
            ans += reward[i].second;
        return ans;
    }
};
int main()
{
    Solution ans;
    vector<int> a = {5, 4, 5, 6, 7, 1, 2};
    vector<int> b = {7, 4, 5, 4, 4, 2, 3};
    cout << ans.miceAndCheese(a, b, 7);
    return 0;
}