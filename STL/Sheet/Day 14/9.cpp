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

vector<int> maxMinWindow(vector<int> a, int n)
{
    vector<int> ans(n, INT_MIN);

    vector<int> prev(n), next(n);
    stack<int> s;

    // to calculate index of prev smaller element that current element
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    // to calculate index of next smaller element that current element
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // the current element is the min of window from the prev smallest element to the next smallest element.
    for (int i = 0; i < n; i++)
    {
        int size = next[i] - prev[i] - 1;
        ans[size - 1] = max(ans[size - 1], a[i]);
    }

    int mx = ans[n - 1];
    // a smaller window will have maximum or equal value from its larger window
    // for a window size x, it can take any value that is valid for window size x+1.
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], mx);
        mx = max(mx, ans[i]);
    }

    return ans;
}
#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif