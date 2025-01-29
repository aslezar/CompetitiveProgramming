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

void pushInSortedStack(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }

    if (stack.top() > num)
    {
        int top = stack.top();
        stack.pop();
        pushInSortedStack(stack, num);
        stack.push(top);
    }
    else
    {
        stack.push(num);
    }
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int top = stack.top();
    stack.pop();
    sortStack(stack);

    pushInSortedStack(stack, top);
}

#undef int

#ifdef LOCAL_RUN

int main()
{

    cout << '\n';

    return 0;
}

#endif