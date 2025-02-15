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
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int ans = 0;

        stack<int> s;
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        s = stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            int area = 1 + (i - left[i] - 1) + (right[i] - i - 1);
            area *= heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{

    cout << '\n';

    return 0;
}

#endif