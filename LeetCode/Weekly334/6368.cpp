#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        vector<int> ans;
        long long rem = 0;
        for (int i = 0; i < word.length(); i++)
        {
            rem *= 10;
            rem += (word[i] - '0');
            rem %= m;
            if (rem)
                ans.push_back(0);
            else
                ans.push_back(1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}