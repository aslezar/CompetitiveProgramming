#include <iostream>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    using ll = long long;
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        queue<pair<TreeNode *, int>> d;
        d.push({root, 0});
        while (!d.empty())
        {
            ll l_idx = d.front().second, r_idx = d.back().second;
            int n = (int)d.size();
            for (int i = 0; i < n; i++)
            {
                auto x = d.front();
                d.pop();
                auto idx = x.second;
                if (x.first->left)
                    d.push({x.first->left, (ll)2 * idx});
                if (x.first->right)
                    d.push({x.first->right, (ll)2 * idx + 1});
            }
            ans = max(ans, int(r_idx - l_idx + 1));
        }
        return ans;
    }
};
int main()
{

    return 0;
}