#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        int count = 0;

        for (auto &num : nums)
        {
            string s = to_string(num);
            // cout << s << endl;
            unordered_set<int> seen;
            count += freq[num];
            seen.insert(num);

            for (int index = 0; index < s.length(); index++)
            {
                for (int index2 = index + 1; index2 < s.length(); index2++)
                {
                    swap(s[index], s[index2]);
                    // cout << s << endl;
                    int cand = stoi(s);
                    // int cand = 0;
                    if (!seen.count(cand))
                    {
                        count += freq[cand];
                        seen.insert(cand);
                    }
                    for (int index3 = 0; index3 < s.length(); index3++)
                    {
                        for (int index4 = index3 + 1; index4 < s.length(); index4++)
                        {
                            if (index == index3 && index2 == index4)
                                continue;

                            swap(s[index3], s[index4]);
                            // cout << s << endl;

                            int cand = stoi(s);
                            // int cand = 0;
                            if (!seen.count(cand))
                            {
                                count += freq[cand];
                                seen.insert(cand);
                            }
                            swap(s[index3], s[index4]);
                        }
                    }
                    swap(s[index], s[index2]);
                }
            }
            freq[num]++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();
    vector<int> nums = {1023, 2310, 2130, 213};
    cout << obj->countPairs(nums) << endl;
    return 0;
}
