#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int maximizeGreatness(vector<int> &n)
    {
        if (n.size() == 1)
            return 0;
        int ans = 0;
        sort(n.begin(), n.end());
        int l = 0;
        for (int i = 0; i < n.size(); i++)
        {
            while (l < n.size() && n[l] <= n[i])
                l++;
            if (l == n.size())
                return ans;
            ans++;
            l++;
        }
        return ans;
    }
};
int main()
{

    return 0;
}