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
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

// Function to push an element x in a queue.
void MyQueue ::push(int x)
{
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    if (front == rear)
    {
        return -1;
    }
    return arr[front++];
}

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif