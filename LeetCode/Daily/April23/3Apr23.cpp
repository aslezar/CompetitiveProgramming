#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        while (i <= j)
        {
            ans++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }
        return ans;
    }
};
int main()
{

    return 0;
}