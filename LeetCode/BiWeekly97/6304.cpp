#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define el << '\n'
#define ws << ' '

int maxCount(vector<int> &banned, int n, int maxSum)
{
    set<int> a;
    for (int i = 0; i < banned.size(); i++)
    {
        a.insert(banned[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a.find(i) == a.end())
        {
            maxSum -= i;
            if (maxSum > 0)
                ans++;
            else
                break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}