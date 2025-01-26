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
    int median(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int k = (n * n) / 2 + 1;
        priority_queue<int> pq;
        for (auto &row : mat)
        {
            for (auto &ele : row)
            {
                pq.push(ele);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};

class Solution
{
public:
    int median(vector<vector<int>> &mat)
    {
        int l = 1, r = 2000;
        int n = mat.size();
        int k = (n * n) / 2;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            int cnt = 0;
            for (auto &row : mat)
            {
                cnt += (upper_bound(row.begin(), row.end(), mid) - row.begin());
            }

            if (cnt <= k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    /*
        1 3 5
        2 6 9
        3 6 9
    */

    vii mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << s.median(mat);
    cout << '\n';

    return 0;
}

#endif