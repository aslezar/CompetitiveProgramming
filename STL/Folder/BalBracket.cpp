#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> syb = {
        {'[', -1},
        {'{', -2},
        {'(', -3},
        {']', 1},
        {'}', 2},
        {')', 3},
    };
    bool isValid(string str)
    {
        stack<char> s;
        for (auto &&bracket : str)
        {
            if (syb[bracket] < 0)
                s.push((bracket));
            else if (syb[bracket] > 0)
            {
                if (s.empty() || syb[s.top()] + syb[bracket] != 0)
                    return 0;
                s.pop();
            }
        }
        return s.empty();
    }
};
