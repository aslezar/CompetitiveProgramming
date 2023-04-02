#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    long long makeSubKSumEqual(vector<int> &arr, int k)
    {
        vector<long long> &sum;
        long long ans = 0;
        long long min = 0, max = 0, csum = 0;
        for (size_t i = 0; i < k; i++)
            csum = csum + arr[i];
        sum.push_back(csum);

        // max = min = csum;
        // cout << csum << ' ';

        for (size_t i = 1; i < arr.size(); i++)
        {
            csum = csum + arr[(i + k - 1) % arr.size()] - arr[i - 1];
            sum.push_back(csum);
            // cout << csum << ' ';
            // if (csum < min)
            //     min = csum;
            // if (csum > max)
            //     max = csum;
        }
        cout << '\n';
        return max - min;
    }
};
int main()
{

    return 0;
}