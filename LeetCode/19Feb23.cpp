#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{

    return 0;
}
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return {};
        ans.push_back({root->val});
        stack<TreeNode *> lr;
        stack<TreeNode *> rl;
        lr.push(root);
        while (!(lr.empty() && rl.empty()))
        {
            vector<int> t;
            while (!lr.empty())
            {
                if (lr.top()->right != nullptr)
                {
                    t.push_back(lr.top()->right->val);
                    rl.push(lr.top()->right);
                }
                if (lr.top()->left != nullptr)
                {
                    t.push_back(lr.top()->left->val);
                    rl.push(lr.top()->left);
                }
                lr.pop();
            }
            if (!t.empty())
            {
                ans.push_back(t);
                t.clear();
            }
            while (!rl.empty())
            {
                if (rl.top()->left != nullptr)
                {
                    t.push_back(rl.top()->left->val);
                    lr.push(rl.top()->left);
                }
                if (rl.top()->right != nullptr)
                {
                    t.push_back(rl.top()->right->val);
                    lr.push(rl.top()->right);
                }
                rl.pop();
            }
            if (!t.empty())
                ans.push_back(t);
        }
        return ans;
    }
};