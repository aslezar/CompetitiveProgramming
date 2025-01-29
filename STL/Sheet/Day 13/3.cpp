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

class MyStack
{
    queue<int> q1;

public:
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop()
    {
        int size = q1.size();
        if (size == 0)
            return -1;

        for (int i = 0; i < size - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top()
    {
        int size = q1.size();
        if (size == 0)
            return -1;

        for (int i = 0; i < size - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        q1.push(top);
        return top;
    }

    bool empty() { return q1.empty(); }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif