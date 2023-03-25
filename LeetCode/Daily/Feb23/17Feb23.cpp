#include <iostream>
#include <climits>
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
    int ans = INT_MAX;
    int value = -1;

public:
    int minDiffInBST(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        minDiffInBST(root->left);
        if (value != -1)
            ans = min(ans, root->val - value);
        if (ans == 1)
            return 0;
        value = root->val;
        cout << value << '\n';
        minDiffInBST(root->right);
        return ans;
    }
};
int main()
{

    return 0;
}