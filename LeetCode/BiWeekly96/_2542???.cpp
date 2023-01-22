// 2542. Maximum Subsequence Score
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define el << '\n'

long long ans;
void backtrack(vector<int> &nums1, vector<int> &nums2, int k, long long sum, long long minterm, int index, int terms)
{

    if (index >= nums1.size())
    {
        if (terms == k)
        {
            ans = ans > (sum * minterm) ? ans : (sum * minterm);
        }
        return;
    }

    long long t1 = sum + nums1[index];
    int t2 = (minterm < nums2[index] ? minterm : nums2[index]);
    // else
    // {
    //     backtrack(nums1, nums2, k, sum, minterm, index + 1, terms);
    // }
    if (ans < (t1 * t2))
        backtrack(nums1, nums2, k, t1, t2, index + 1, terms + 1); // included
    else
        backtrack(nums1, nums2, k, sum, minterm, index + 1, terms); // not-included
    // if(ans<(sum*min))
    //     ans=sum*min;
    // if (!k)
    // {
    //     if (seq.size() > 1)
    //     {
    //         result.insert(seq);
    //     }
    //     return;
    // }
    // if((terms+1)==k)
    // {
    //     return;
    // }
    // if (!indices || indices!=k)
    // {
    // sum+=nums1[index];
    // minterm=min(minterm,nums2[index]);
}
long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    ans = INT_MIN;
    backtrack(nums1, nums2, k, 0, INT_MAX, 0, 0);
    return ans;
}
int main()
{
    vector<int> num1({4, 2, 3, 1, 1});
    vector<int> num2({7, 5, 10, 9, 6});
    cout << maxScore(num1, num2, 1);
    return 0;
}