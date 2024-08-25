#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool swapable(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        if (s1.length() != s2.length())
        {
            if (s1.length() < s2.length())
                swap(s1, s2);
            while (s1.length() != s2.length())
                s2 = '0' + s2;
        }
        assert(s1.length() == s2.length());
        // cout << s1 << ' ' << s2 << "\n";
        int k = 2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (k == 0)
                    return false;
                for (int j = i + 1; j < s1.length(); j++)
                {
                    if (s1[j] == s2[i] && s2[j] == s1[i])
                    {
                        swap(s2[i], s2[j]);
                        k--;
                        break;
                    }
                }
                if (s1[i] != s2[i])
                {
                    for (int j = i + 1; j < s1.length(); j++)
                    {
                        if (s2[j] == s1[i] && s2[j] != s1[j])
                        {
                            swap(s2[i], s2[j]);
                            k--;
                            break;
                        }
                    }
                }
                if (s1[i] != s2[i])
                    return false;
            }
        }
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        // cout << n1 << ' ' << n2 << "\n\n";
        return n1 == n2;
    }
    int countPairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (swapable(nums[i], nums[j]))
                {
                    // cout << nums[i] << ' ' << nums[j] << "\n";
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1023, 2310, 2130, 213};
    cout << s.countPairs(v) << "\n";
    return 0;
}