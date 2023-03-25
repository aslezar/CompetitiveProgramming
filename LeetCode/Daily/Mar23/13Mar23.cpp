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
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return 1;
        if (left == NULL || right == NULL || (left->val != right->val))
            return 0;
        return helper(left->left, right->right) && (helper(left->right, right->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        return helper(root->left, root->right);
    }
};
class Solution2
{
public:
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return 1;
        if (left == NULL || right == NULL || (left->val != right->val))
            return 0;
        return helper(left->left, right->right) && (helper(left->right, right->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        return helper(root->left, root->right);
    }
};
int main()
{

    return 0;
}