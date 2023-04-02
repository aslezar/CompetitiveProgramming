#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0;
        int no0 = 0;
        bool start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                start = 1;
                no0++;
                cout << "Hello1 " << no0 << ' ' << i << '\n';
            }
            else
            {
                cout << "Hello2 " << no0 << ' ' << i << '\n';
                if (start == 1)
                {
                    int no1 = 0;
                    for (; i < s.size(); i++)
                    {
                        if (s[i] == '1')
                        {
                            no1++;
                        }
                        else
                            break;
                    }
                    int t = (min(no0, no1) * 2);
                    if (ans < t)
                        ans = t;
                    i--;
                }
                // cout << "hello3";
                start = 0;
                no0 = 0;
            }
        }
        return ans;
    }
};
int main()
{
    Solution ans;
    cout << ans.findTheLongestBalancedSubstring("01000111");
    return 0;
}