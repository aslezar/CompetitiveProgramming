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
    int helper(TreeNode *root, int no)
    {
        if (root == NULL)
            return 0;
        no = no * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            return no;
        return helper(root->left, no) + helper(root->right, no);
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        return helper(root, sum);
    }
};
int main()
{

    return 0;
}