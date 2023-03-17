#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode *help(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++)
            index[inorder[i]] = i;
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
    }

    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &porder, int istart, int iend, int pstart, int pend, unordered_map<int, int> &index)
    {
        if (istart > iend || pstart > pend)
            return nullptr;
        TreeNode *root = new TreeNode(porder[pend]);
        int leftSubtreeSize = index[porder[pend]] - istart;
        root->left = buildTreeHelper(inorder, porder, istart, index[porder[pend]] - 1, pstart, pstart + leftSubtreeSize - 1, index);
        root->right = buildTreeHelper(inorder, porder, index[porder[pend]] + 1, iend, pstart + leftSubtreeSize, pend - 1, index);
        return root;
    }
};

int main()
{

    return 0;
}