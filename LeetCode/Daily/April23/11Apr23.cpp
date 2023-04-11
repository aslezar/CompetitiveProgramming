#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    string removeStars(string s)
    {
        string ans;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}