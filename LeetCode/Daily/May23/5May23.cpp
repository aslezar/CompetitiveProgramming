#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    bool isVow(char &s)
    {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k)
    {
        int vow = 0;
        for (int i = 0; i < k; i++)
        {
            if (isVow(s[i]))
            {
                vow++;
            }
        }
        int ans = vow;
        for (int i = k; i < s.length(); i++)
        {
            if (isVow(s[i]))
            {
                vow++;
            }
            if (isVow(s[i - k]))
                vow--;
            if (ans < vow)
                ans = vow;
        }
        return ans;
    }
};

int main()
{

    return 0;
}