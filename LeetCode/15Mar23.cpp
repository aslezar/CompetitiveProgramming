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
    bool isCompleteTree(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (!q.empty())
        {
            if (!q.front() == NULL)
            {
                while (q.empty())
                {
                    if (q.front() != NULL)
                        return 0;
                    q.pop();
                }
                return 1;
            }
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
        return 0;
    }
};
int main()
{

    return 0;
}