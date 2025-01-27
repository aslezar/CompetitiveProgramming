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
    int findPages(vector<int> &A, int B)
    {
        int n = A.size();
        if (B > n)
        {
            return -1;
        }
        if (B == n)
        {
            return *max_element(A.begin(), A.end());
        }

        auto isValuePossible = [&](int mxPages) -> bool
        {
            int i = 0;
            for (int j = 0; j < B - 1; j++)
            {
                int pages = 0;
                while (i < n && pages + A[i] <= mxPages)
                {
                    pages += A[i];
                    i++;
                }
            }
            int pages = 0;
            for (; i < n; i++)
            {
                pages += A[i];
            }
            return pages <= mxPages;
        };

        int l = *min_element(A.begin(), A.end());
        int r = accumulate(A.begin(), A.end(), 0);
        int ans = INT_MAX;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isValuePossible(mid))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
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