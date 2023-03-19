#include <iostream>
#include <stack>
using namespace std;

#define el << '\n'
#define ws << ' '

int *greatest(int *a, int size)
{
    stack<int> s;
    int *ans = new int[size];
    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        // cout << s.top() ws;
        ans[s.top()] = -1;
        s.pop();
    }
    return ans;
}
int main()
{
    int a[] = {4, 5, 2, 25, 7, 8};
    int *ans = greatest(a, 6);
    for (int i = 0; i < 6; i++)
        cout << ((ans[i] != -1) ? a[ans[i]] : -1) ws;
    cout el;

    return 0;
}