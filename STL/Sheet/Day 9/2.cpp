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

typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    // Create a recursive function, that will add one more element on every call.
    void subsetsWithDupHelper(vi &nums, int index, vii &ans, vi &cur)
    {

        ans.push_back(cur);

        // pick a number
        for (int i = index; i < nums.size(); i++)
        {
            // This will ensure that we are not adding duplicate elements from index to n
            if (i == index || nums[i] != nums[i - 1])
            {
                cur.push_back(nums[i]);
                subsetsWithDupHelper(nums, i + 1, ans, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vii ans;
        vi cur;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(nums, 0, ans, cur);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    vi v = {1, 2, 2};
    auto ans = s.subsetsWithDup(v);
    debug(ans);

    cout << '\n';

    return 0;
}

#endif