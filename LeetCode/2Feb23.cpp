#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    bool compare(string a, string b, map<char, int> order)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (b.size() <= i)
                return false;
            if (a[i] == b[i])
            {
                continue;
            }
            else if (order[a[i]] > order[b[i]])
                return false;
            else
                return true;
        }
        return true;
    }
    bool isAlienSorted(vector<string> &words, string order)
    {
        map<char, int> orders;
        for (int i = 0; i < 26; i++)
        {
            orders[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!compare(words[i], words[i + 1], orders))
            {
                return false;
            }
        }
        return true;
    }
};