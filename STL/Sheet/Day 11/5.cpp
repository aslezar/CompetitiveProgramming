#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution2
{
public:
    int p1 = 0, p2 = 0;
    int getMin(vi &nums1, vi &nums2)
    {
        if (p1 < nums1.size() && p2 < nums2.size())
        {
            return nums1[p1] <= nums2[p2] ? nums1[p1++] : nums2[p2++];
        }
        else if (p1 < nums1.size())
        {
            return nums1[p1++];
        }
        else if (p2 < nums2.size())
        {
            return nums2[p2++];
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size(), m = nums2.size();

        p1 = 0, p2 = 0;

        double ans = 0;

        if ((n + m) % 2 == 0)
        {
            for (int i = 0; i < (n + m) / 2 - 1; i++)
            {
                getMin(nums1, nums2);
            }
            ans += getMin(nums1, nums2);
            ans += getMin(nums1, nums2);
            ans /= 2;
        }
        else
        {
            for (int i = 0; i < (n + m) / 2; i++)
            {
                getMin(nums1, nums2);
            }
            ans = getMin(nums1, nums2);
        }
        return ans;
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n2 < n1)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;

        int k = n / 2;
        int l = 0, r = n1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int mid2 = k - mid;

            int l1 = mid == 0 ? INT_MIN : nums1[mid - 1];
            int r1 = mid == n1 ? INT_MAX : nums1[mid];

            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int r2 = mid2 == n2 ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1)
            {
                // ans
                if (n & 1)
                {
                    return min(r1, r2);
                }
                return (double(max(l1, l2)) + min(r1, r2)) / 2;
            }
            else if (max(l1, r1) >= min(l2, r2))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif