#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 1)
            return 1;
        int ans = 0;
        int count = 1;
        for (int i = 0; i < chars.size(); i++)
        {
            if (i + 1 < chars.size() && chars[i] == chars[i + 1])
                count++;
            else
            {
                chars[ans++] = chars[i];
                if (count > 1)
                {
                    if (count > 9)
                    {
                        if (count > 99)
                        {
                            if (count > 999)
                            {
                                chars[ans++] = count / 1000 + '0';
                                count -= (count / 1000) * 1000;
                            }
                            chars[ans++] = count / 100 + '0';
                            count -= (count / 100) * 100;
                        }
                        chars[ans++] = count / 10 + '0';
                        count -= (count / 10) * 10;
                    }
                    chars[ans++] = count + '0';
                }
                // string str = to_string(count);
                // for (char c : str)
                // {
                //     chars.push_back(c);
                // }
                count = 1;
            }
        }
        chars.resize(ans);
        return ans;
    }
};
int main()
{

    return 0;
}