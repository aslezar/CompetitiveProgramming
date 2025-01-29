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

class MyQueue
{
    stack<int>  input,output;

public:
    MyQueue() {}

    void push(int x) { input.push(x); }

    int pop()
    {
        int top = peek();
        if (top != -1)
            output.pop();
        return top;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty())
        {
            return -1;
        }
        int top = output.top();
        return top;
    }

    bool empty() { return output.empty() && input.empty(); }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif