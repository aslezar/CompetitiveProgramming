#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    unordered_map<char, int> syb = {
        {'[', -1},
        {'{', -2},
        {'(', -3},
        {']', -1},
        {'}', -2},
        {')', -3},
    };
    bool isValid(string s)
    {
        stack<char> s;
        for (auto &&bracket : s)
        {
            if (syb[bracket] < 0)
                s.push_back(bracket);
            else if (syb[bracket] > 0)
            {
                if (s.empty() || syb[s.front()] + syb[bracket] != 0)
                    return 0;
                s.pop_back();
            }
        }
        return s.empty();
    }
};
int main()
{

    return 0;
}