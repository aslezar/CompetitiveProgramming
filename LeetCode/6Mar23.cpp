#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int missing = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == missing)
            {
                missing++;
                k--;
                if (k == 0)
                    return missing;
            }
        }

        return missing + k;
    }
};

int main()
{

    return 0;
}