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
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        vector<int> ans;
        map<ll, ll> freq;
        set<pair<ll, ll>, greater<pair<ll, ll>>> s;
        for (int i = 0; i < k; i++)
        {
            s.erase({freq[nums[i]], nums[i]});
            freq[nums[i]]++;
            s.insert({freq[nums[i]], nums[i]});
        }
        ll sum = 0;
        auto it = s.begin();
        for (int i = 0; i < x; i++)
        {
            if (it == s.end())
                break;
            sum += (it->second * it->first);
            it++;
        }
        ans.push_back(sum);

        for (int i = k; i < nums.size(); i++)
        {
            s.erase({freq[nums[i - k]], nums[i - k]});
            freq[nums[i - k]]--;
            s.insert({freq[nums[i - k]], nums[i - k]});

            s.erase({freq[nums[i]], nums[i]});
            freq[nums[i]]++;
            s.insert({freq[nums[i]], nums[i]});

            sum = 0;
            it = s.begin();
            for (int i = 0; i < x; i++)
            {
                if (it == s.end())
                    break;
                sum += (it->second * it->first);
                it++;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    // [3,8,7,8,7,5], k = 2, x = 2
    vi nums = {3, 8, 7, 8, 7, 5};
    int k = 2;
    int x = 2;
    auto ans = s.findXSum(nums, k, x);
    debug(ans);

    //  [1,1,2,2,3,4,2,3], k = 6, x = 2
    nums = {1, 1, 2, 2, 3, 4, 2, 3};
    k = 6;
    x = 2;
    ans = s.findXSum(nums, k, x);
    debug(ans);
    cout << '\n';

    return 0;
}

#endif