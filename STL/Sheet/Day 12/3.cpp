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

class Solution
{
public:
    vector<int> maxCombinations(int n, int K, vector<int> &A, vector<int> &B)
    {
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        typedef pair<int, int> pii;
        typedef pair<int, pii> ipii;
        priority_queue<ipii> pq;
        set<pii> vis;

        vector<int> ans;

        pq.push({A[0] + B[0], {0, 0}});
        vis.insert({0, 0});

        for (int i = 0; i < K; i++)
        {
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.first);

            pii p1 = {top.second.first + 1, top.second.second};
            pii p2 = {top.second.first, top.second.second + 1};

            if (!vis.count(p1) && p1.first < n)
            {
                pq.push({A[p1.first] + B[p1.second], p1});
                vis.insert(p1);
            }

            if (!vis.count(p2) && p2.second < n)
            {
                pq.push({A[p2.first] + B[p2.second], p2});
                vis.insert(p2);
            }
        }

        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif