#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int partitionString(string s)
    {
        int ans = 0;
        vector<bool> v(26, 0);
        for (size_t i = 0; i < s.size(); i++)
        {
            if (v[s[i] - 'a'] == 0)
            {
                v[s[i] - 'a'] = 1;
            }
            else
            {
                cout << i << ' ';
                ans++;
                for (size_t i = 0; i < 26; i++)
                    v[i] = 0;
                v[s[i] - 'a'] = 1;
            }
        }
        ans++;
        return ans;
    }
};
int main()
{
    Solution ans;
    cout << ans.partitionString("abacaba");
    return 0;
}