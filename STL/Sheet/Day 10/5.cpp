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
    const map<char, pair<int, int>> directions = {{'U', {-1, 0}}, {'D', {+1, 0}}, {'L', {0, -1}}, {'R', {0, +1}}};
    void findPathHelper(vector<vector<int>> &mat, int curR, int curC, string &path, vector<string> &ans)
    {
        int n = mat.size();
        auto isInLimit = [&n](int i, int j) -> bool
        {
            return i >= 0 && i < n && j >= 0 && j < n;
        };

        // If out of array return
        if (!isInLimit(curR, curC) || mat[curR][curC] == 0)
        {
            return;
        }

        // If reach destination, push ans and return
        if (curR == n - 1 && curC == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // Mark cell as visited
        mat[curR][curC] = -1;

        for (auto &dir : directions)
        {
            int i = curR + dir.second.first;
            int j = curC + dir.second.second;
            if (isInLimit(i, j) && mat[i][j] == 1)
            {
                path.push_back(dir.first);
                findPathHelper(mat, i, j, path, ans);
                path.pop_back();
            }
        }

        // Mark cell as unvisited
        mat[curR][curC] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Problem Discuss
        // Question Ask
        // Test Case Discuss
        // Edge Case Discuss
        // Brute Force
        // Optimize
        // Dry Run
        // Time Complexity

        vector<string> ans;
        string path;
        findPathHelper(mat, 0, 0, path, ans);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    vii a;
    s.findPath(a);

    cout << '\n';

    return 0;
}

#endif