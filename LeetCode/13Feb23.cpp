#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int ans = high - low;
        ans /= 2;
        if (low % 2 || high % 2)
            ans++;
        return ans;
    }
};
int main()
{
    return 0;
}