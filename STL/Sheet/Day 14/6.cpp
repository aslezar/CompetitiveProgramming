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

class MinStack
{
    long long mn;
    vector<long long> s;

public:
    MinStack() { mn = 0; }

    void push(int val)
    {
        if (s.empty())
        {
            s.push_back(val);
            mn = val;
        }
        else if (val < mn)
        {
            // save modified value
            s.push_back(2ll * val - mn);
            mn = val;
        }
        else
        {
            s.push_back(val);
        }
    }

    void pop()
    {
        if (s.empty())
            return;
        if (s.back() < mn)
        {
            // modified value
            mn = (2ll * mn - s.back());
        }
        return s.pop_back();
    }

    int top()
    {
        if (s.empty())
            return -1;
        if (s.back() < mn)
        {
            // modified value
            return mn;
        }
        return s.back();
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        return mn;
    }
};

class MinStack2
{
    vector<pair<int, int>> s;

public:
    MinStack2() {}

    void push(int val)
    {
        int mn = val;
        if (!s.empty())
        {
            mn = min(mn, getMin());
        }
        s.push_back({val, mn});
    }

    void pop()
    {
        if (s.empty())
            return;
        s.pop_back();
    }

    int top()
    {
        if (s.empty())
            return -1;
        return s.back().first;
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif