// 2540. Minimum Common Value
#include <iostream>
#include <vector>
using namespace std;

#define el cout << '\n';

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            if (nums1[i] < nums2[j])
                break;
        }
    }
    return -1;
}
int main()
{
    vector<int> num1({1, 2, 3});
    vector<int> num2({2, 4});
    cout << getCommon(num1, num2);

    return 0;
}