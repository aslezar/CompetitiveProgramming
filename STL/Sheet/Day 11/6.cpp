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

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 + n2;
        if (n2 < n1)
            return kthElement(b, a, k);

        k--; // 9

        int l = 0, r = n1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int mid2 = k - mid;
            if (mid2 < 0)
            {
                r = mid - 1;
                continue;
            }
            if (mid2 > n2)
            {
                l = mid + 1;
                continue;
            }

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid - 1 >= 0)
                l1 = a[mid - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];
            if (mid < n1)
                r1 = a[mid];
            if (mid2 < n2)
                r2 = b[mid2];

            if (l1 > r2)
            {
                r = mid - 1;
            }
            else if (l2 > r1)
            {
                l = mid + 1;
            }
            else
            {
                assert(l1 <= r2 && l2 <= r1);
                return min(r1, r2);
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