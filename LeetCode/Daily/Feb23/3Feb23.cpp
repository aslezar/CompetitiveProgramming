#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string ans;
        int size = s.size();
        int charSec = 2 * (numRows - 1);

        for (int row = 0; row < numRows; ++row)
        {
            int index = row;

            while (index < size)
            {
                ans += s[index];
                if (row != 0 && row != numRows - 1)
                {
                    int charbw = charSec - 2 * row;
                    int secindex = index + charbw;

                    if (secindex < size)
                    {
                        ans += s[secindex];
                    }
                }
                index += charSec;
            }
        }

        return ans;
    }
};