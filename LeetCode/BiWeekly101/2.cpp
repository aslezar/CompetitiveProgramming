#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < 26; i++)
            m[i + 'a'] = i + 1;
        for (size_t i = 0; i < chars.size(); i++)
            m[chars[i]] = vals[i];
        int cost = 0;
        int ans = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (ans < cost)
                ans = cost;
            cost += m[s[i]];
            if (cost < 0)
                cost = 0;
        }
        return max(ans, cost);
    }
};
int main()
{

    return 0;
}