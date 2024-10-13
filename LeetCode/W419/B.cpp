#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    int dfs(TreeNode *node, vector<int> &perfectSizes)
    {
        if (!node)
            return 0;

        int leftSize = dfs(node->left, perfectSizes);
        int rightSize = dfs(node->right, perfectSizes);

        if (leftSize == -1 || rightSize == -1)
            return -1;

        if (leftSize == rightSize)
        {
            int size = leftSize + rightSize + 1;
            perfectSizes.push_back(size);
            return size;
        }

        return -1;
    }

public:
    int kthLargestPerfectSubtree(TreeNode *root, int k)
    {
        vector<int> perfectSizes;
        dfs(root, perfectSizes);

        if (perfectSizes.size() < k)
            return -1;

        sort(perfectSizes.rbegin(), perfectSizes.rend());

        return perfectSizes[k - 1];
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