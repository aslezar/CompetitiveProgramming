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

namespace soln1
{

    void merge(vector<int> &a, const vector<int> &b)
    {

        int n = a.size(), m = b.size();
        int i = n - 1, j = m - 1;

        a.resize(n + m);
        int k = n + m - 1;

        while (i >= 0 && j >= 0)
        {
            if (a[i] > b[j])
            {
                a[k] = a[i];
                i--;
                k--;
            }
            else
            {
                a[k] = b[j];
                j--;
                k--;
            }
        }

        while (i >= 0)
        {
            a[k] = a[i];
            i--;
            k--;
        }

        while (j >= 0)
        {
            a[k] = b[j];
            j--;
            k--;
        }
    }

    vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
    {
        vector<int> ans;

        if (k == 0)
            return ans;
        if (k == 1)
            return kArrays[0];

        assert(k >= 2);

        for (auto &arr : kArrays)
        {
            merge(ans, arr);
        }

        return ans;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    struct ArrayEle
    {
        int value;
        int arr_index;
        int index;

        ArrayEle(int v, int a_idx, int i) : value(v), arr_index(a_idx), index(i) {}
    };

    auto comp = [](ArrayEle &a, ArrayEle &b) -> bool
    {
        return a.value > b.value;
    };

    priority_queue<ArrayEle, vector<ArrayEle>, decltype(comp)> pq(comp);

    for (int i = 0; i < k; i++)
    {
        pq.emplace(kArrays[i][0], i, 0);
    }

    vector<int> ans;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        ans.push_back(top.value);

        auto &arr = kArrays[top.arr_index];

        if (top.index + 1 < arr.size())
        {
            pq.emplace(arr[top.index + 1], top.arr_index, top.index + 1);
        }
    }

    return ans;
}

#undef int

#ifdef LOCAL_RUN

int main()
{
    vector<vector<int>> kArrays = {{3, 5, 9}, {1, 2, 3, 8}};
    auto ans = mergeKSortedArrays(kArrays, 2);
    debug(ans);

    return 0;
}

#endif