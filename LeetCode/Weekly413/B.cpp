#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     vector<int> resultsArray(vector<vector<int>> &queries, int k)
//     {

//         vector<int> ans;

//         int eleAtK = INT_MIN;
//         for (int i = 0; i < k - 1; i++)
//         {
//             int curDist = abs(queries[i][0]) + abs(queries[i][1]);
//             eleAtK = max(eleAtK, curDist);
//             ans.push_back(-1);
//         }

//         for (size_t i = k - 1; i < queries.size(); i++)
//         {
//             int curDist = abs(queries[i][0]) + abs(queries[i][1]);
//             if(curDist<=)
//         }
//         return ans;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     vector<int> resultsArray(vector<vector<int>> &queries, int k)
//     {

//         vector<int> ans;
//         multiset<int> dist;

//         for (int i = 0; i < queries.size(); i++)
//         {
//             int x = abs(queries[i][0]);
//             int y = abs(queries[i][1]);
//             dist.insert(x + y);
//             if (dist.size() < k)
//                 ans.push_back(-1);
//             else
//                 ans.push_back(*next(dist.begin(), k - 1));
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> resultsArray(vector<vector<int>> &queries, int k)
    {
        vector<int> ans;
        priority_queue<int> maxHeap;

        for (const auto &query : queries)
        {
            int distance = abs(query[0]) + abs(query[1]);
            maxHeap.push(distance);

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }

            if (maxHeap.size() < k)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(maxHeap.top());
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // [[6,10],[0,-10],[2,-6]]
    vector<vector<int>> queries = {{6, 10}, {0, -10}, {2, -6}};

    // [[1,2],[3,4],[2,3],[-3,0]]
    // vector<vector<int>> queries = {{1, 2}, {3, 4}, {2, 3}, {-3, 0}};
    int k = 2;
    vector<int> ans = s.resultsArray(queries, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}