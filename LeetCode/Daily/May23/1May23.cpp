#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        salary.pop_back();
        salary.erase(salary.begin());
        double ans = 0;
        for (size_t i = 0; i < salary.size(); i++)
        {
            ans += salary[i];
        }
        return ans / salary.size();
    }
};
int main()
{

    return 0;
}