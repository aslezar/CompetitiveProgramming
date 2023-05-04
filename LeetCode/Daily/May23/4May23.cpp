#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    string predictPartyVictory(string s)
    {
        if (s.length() == 1)
        {
            if (s[0] == 'R')
                return "Radiant";
            return "Dire";
        }
        int R = 0, D = 0, X = 0;
        int sR = 0, sD = 0;
        for (auto &&i : s)
        {
            if (i == 'R')
                R++;
            else
                D++;
        }
        while (D != 0 || R != 0)
        {
            for (auto &&i : s)
            {
                if (i == 'X')
                    continue;
                if (i == 'R')
                {
                    if (sR > 0)
                    {
                        i = 'X';
                        sR--;
                    }
                    else
                    {
                        if (D == 0)
                            return "Radiant";
                        D--;
                        sD++;
                    }
                }
                else
                {
                    if (sD > 0)
                    {
                        i = 'X';
                        sD--;
                    }
                    else
                    {
                        if (R == 0)
                            return "Dire";
                        R--;
                        sR++;
                    }
                }
            }
        }
        return "hello";
    }
};
int main()
{
    Solution ans;
    cout << ans.predictPartyVictory("DDRRR");
    return 0;
}