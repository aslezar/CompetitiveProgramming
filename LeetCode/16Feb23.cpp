#include <iostream>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ans = 1;
        if (root->left != nullptr)
        {
            ans = maxDepth(root->left) + 1;
        }
        if (root->right != nullptr)
        {
            ans = max(ans, maxDepth(root->right) + 1);
        }
        return ans;
    }
};

int main()
{

    return 0;
}