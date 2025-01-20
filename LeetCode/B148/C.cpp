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
    pii ans;
    pii helper(int u, vector<vector<pii>> &g, vector<int> &nums, unordered_map<int, int> &visited)
    {
        debug(u, visited);
        visited[nums[u]] = u;
        int longest = 0;
        int nodes = 0;
        for (auto &v : g[u])
        {
            if (visited.count(nums[v.first]) == 0)
            {
                auto res = helper(v.first, g, nums, visited);
                if (res.first + v.second > longest)
                {
                    longest = res.first + v.second;
                    nodes = res.second;
                }
                else if (res.first + v.second == longest)
                {
                    nodes = min(nodes, res.second);
                }
            }
            else
            {
                unordered_map<int, int> temp;
                pii res = helper(v.first, g, nums, visited);
                if (ans.first < res.first + v.second)
                {
                    ans = {res.first + v.second, res.second + 1};
                }
                else if (ans.first == res.first + v.second)
                {
                    ans.second = min(ans.second, res.second + 1);
                }
            }
        }
        visited.erase(nums[u]);
        return {longest, nodes + 1};
    }
    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<pii>> gr(n);
        vector<vector<pii>> g(n);

        for (auto &e : edges)
        {
            gr[e[0]].push_back({e[1], e[2]});
            gr[e[1]].push_back({e[0], e[2]});
        }

        auto &g = gr;

        // unordered_set<int> vis;
        // queue<int> q;
        // q.push(0);
        // while (!q.empty())
        // {
        //     auto node = q.front();
        //     q.pop();
        //     vis.insert(node);
        //     for (auto &v : gr[node])
        //     {
        //         if (vis.count(v.first) == 0)
        //         {
        //             g[node].push_back(v);
        //             q.push(v.first);
        //         }
        //     }
        // }

        ans = {0, 0};
        unordered_map<int, int> visited;
        helper(0, g, nums, visited);
        return {ans.first, ans.second};
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    //  edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 4}, {2, 5, 6}};
    vector<int> nums = {2, 1, 2, 1, 3, 1};
    auto res = s.longestSpecialPath(edges, nums);
    debug(res);
    cout << '\n';

    // [[1,0,1],[1,2,6]]
    // [4,3,5]
    edges = {{1, 0, 1}, {1, 2, 6}};
    nums = {4, 3, 5};
    auto res2 = s.longestSpecialPath(edges, nums);
    debug(res2);
    cout << '\n';

    return 0;
}

#endif