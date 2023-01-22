// 2541. Minimum Operations to Make Array Equal II
#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'

long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
{
    long long count1 = 0;
    long long count2 = 0;
    if (k < 1)
        k *= (-1);
    if (k == 0)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] != nums2[i])
                return -1;
        }
        return 0;
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (nums1[i] > nums2[i])
        {
            if ((nums1[i] - nums2[i]) % k == 0)
                count1 += ((nums1[i] - nums2[i]) / k);
            else
                return -1;
        }
        else
        {
            if ((nums2[i] - nums1[i]) % k == 0)
                count2 += ((nums2[i] - nums1[i]) / k);
            else
                return -1;
        }
    }
    if (count1 == count2)
        return count1;
    return -1;
}

int main()
{
    vector<int> num1({4, 3, 1, 4});
    vector<int> num2({1, 3, 7, 1});
    cout << minOperations(num1, num2, 3);

    return 0;
}