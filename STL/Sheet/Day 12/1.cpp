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

template <typename T>
class MinHeap
{
    vector<T> v;

public:
    void push(int value)
    {
        v.push_back(value);
        int i = v.size() - 1;
        int p = (i - 1) / 2;
        while (i >= 1 && v[p] > v[i])
        {
            swap(v[i], v[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }
    int top()
    {
        if (v.size() == 0)
            return -1;
        return v[0];
    }
    void pop()
    {
        if (v.size() == 0)
            return;
        swap(v[0], v.back());
        v.pop_back();
        int index = 0;
        while (index < v.size())
        {
            int minIndex = index;
            int lChild = 2 * minIndex + 1;
            int rChild = 2 * minIndex + 2;
            if (lChild < v.size() && v[lChild] < v[minIndex])
            {
                minIndex = lChild;
            }
            if (rChild < v.size() && v[rChild] < v[minIndex])
            {
                minIndex = rChild;
            }
            if (minIndex != index)
            {
                swap(v[minIndex], v[index]);
                index = minIndex;
            }
            else
            {
                break;
            }
        }
    }
};

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> ans;
    MinHeap<int> pq;
    for (auto &i : q)
    {
        switch (i[0])
        {
        case 0:
            pq.push(i[1]);
            break;

        case 1:
            ans.push_back(pq.top());
            pq.pop();
            break;
        }
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