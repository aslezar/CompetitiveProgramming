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

class MedianFinder
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}

    void addNum(int num)
    {

        left.push(num);

        // Make sure left <= right
        if ((int)left.size() > 0 && (int)right.size() > 0 && left.top() > right.top())
        {
            right.push(left.top());
            left.pop();
        }

        //  Make sure left donot have mora than 1 extra element than right
        if ((int)left.size() - (int)right.size() > 1)
        {
            right.push(left.top());
            left.pop();
        }

        //  Make sure right donot have more elements than left
        if ((int)right.size() - (int)left.size() > 0)
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        int n = left.size();
        int m = right.size();
        if (n + m == 0)
            return 0;
        if ((n + m) % 2 == 1)
        {
            return left.top();
        }
        return (double(left.top()) + double(right.top())) / 2;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    MedianFinder m;

    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    m.addNum(6);
    m.addNum(7);
    cout << m.findMedian();
    m.addNum(4);
    cout << m.findMedian();

    cout << '\n';
    return 0;
}

#endif