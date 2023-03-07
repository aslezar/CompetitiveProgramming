#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int findKthPositive(vector<int> a, int k)
    {
        int size = a.size();
        if (a[0] > k)
            return k;
        k -= (a[0] - 1);
        for (int i = 0; i < size - 1; i++)
        {
            int t = a[i + 1] - a[i] - 1;
            if (t >= k)
                return a[i] + k;
            else
                k -= t;
        }
        return a[size - 1] + k;
    }
};

// class Solution
// {
// public:
//     int findKthPositive(vector<int> arr, int k)
//     {
//         int left = 0, right = arr.size() - 1;
//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if (arr[mid] - mid - 1 < k)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }
//         return left + k;
//     }
// };
int main()
{

    return 0;
}