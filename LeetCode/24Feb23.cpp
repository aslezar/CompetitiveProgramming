#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

int minimumDeviation(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<int> a;
    for (auto &&i : nums)
    {
        a.insert(i);
    }

    int ans = *a.end() - *a.begin();
    while (*a.begin() % 2 == 0 && *a.end() & 1)
    {
        if (!ans)
            return ans;
        if (*a.begin() & 1)
        {
            a.erase(a.begin());
            a.insert(*a.begin() * 2);
        }
        if (*a.end() % 2 == 0)
        {
            a.erase(a.end());
            a.insert(*a.end() / 2);
        }
    }
    return ans;
}
class Solution2
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq; // max heap to store even numbers
        int m = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                pq.push(nums[i]);
                m = min(m, nums[i]);
            }
            else
            {
                pq.push(nums[i] * 2);
                m = min(m, nums[i] * 2);
            }
        }
        int ans = INT_MAX;
        while (!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            ans = min(ans, top - m);
            if (top % 2 != 0)
            {
                break;
            }
            m = min(m, top / 2);
            pq.push(top / 2);
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4};
    cout << minimumDeviation(a);
    return 0;
}