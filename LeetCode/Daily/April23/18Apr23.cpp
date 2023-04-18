#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;
        int i = 0;
        for (; i < min(word1.size(), word2.size()); i++)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        for (; i < word1.size(); i++)
        {
            ans.push_back(word1[i]);
        }
        for (; i < word2.size(); i++)
        {
            ans.push_back(word2[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}