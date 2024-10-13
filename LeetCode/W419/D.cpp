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
    vector<ll> findXSum(vector<int> &nums, int k, int x)
    {
        vector<ll> ans;
        unordered_map<ll, ll> freq;

        set<pair<ll, ll>, greater<pair<ll, ll>>> s;
        set<pair<ll, ll>, greater<pair<ll, ll>>> xTop;

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
            xTop.insert(*it);
            sum += (it->second * it->first);
            it++;
        }

        debug(s, xTop, sum);
        auto it2 = s.begin();
        advance(it2, min(x, (int)s.size()));
        s.erase(s.begin(), it2);
        ans.push_back(sum);
        debug(s, xTop, sum);

        for (int i = k; i < nums.size(); i++)
        {
            if (s.find({freq[nums[i - k]], nums[i - k]}) != s.end())
            {
                s.erase({freq[nums[i - k]], nums[i - k]});
            }
            else
            {
                xTop.erase({freq[nums[i - k]], nums[i - k]});
                sum -= (freq[nums[i - k]] * nums[i - k]);
            }
            freq[nums[i - k]]--;
            s.insert({freq[nums[i - k]], nums[i - k]});

            if (s.find({freq[nums[i]], nums[i]}) != s.end())
            {
                s.erase({freq[nums[i]], nums[i]});
            }
            else
            {
                xTop.erase({freq[nums[i]], nums[i]});
                sum -= (freq[nums[i]] * nums[i]);
            }

            freq[nums[i]]++;
            s.insert({freq[nums[i]], nums[i]});

            while (xTop.size() < x)
            {
                if (s.size() == 0)
                    break;
                auto it = s.begin();
                xTop.insert(*it);
                sum += (it->second * it->first);
                s.erase(it);
            }

            // compare xtop last ele and s first ele
            while (true)
            {
                if (s.size() == 0 || xTop.size() == 0)
                    break;
                auto it = xTop.rbegin();
                auto it2 = s.begin();
                if (it->first < it2->first || (it->first == it2->first && it->second < it2->second))
                {
                    s.insert(*it);
                    xTop.insert(*it2);
                    sum -= (it->first * it->second);
                    sum += (it2->first * it2->second);
                    xTop.erase(*it);
                    s.erase(*it2);
                }
                else
                {
                    break;
                }
            }

            debug(nums[i], s, xTop, sum);

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

    // [5,5,3,5,3] k=4 x=4
    nums = {5, 5, 3, 5, 3};
    k = 4;
    x = 4;
    ans = s.findXSum(nums, k, x);
    debug(ans);

    return 0;
}

#endif