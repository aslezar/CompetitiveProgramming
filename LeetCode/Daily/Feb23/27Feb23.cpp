#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid, int start = 0, int starty = 0, int size = 0)
    {
        Node *ptr = new Node;
        if (grid.size() == 1)
        {
            ptr->isLeaf = 1;
            ptr->val = grid[0][0];
            return ptr;
        }
        if (size == 0)
            size = grid.size();
        if (size == 2)
        {
            if (grid[start][starty] == grid[start + 1][starty] && grid[start][starty] == grid[start][starty + 1] && grid[start][starty] == grid[start + 1][starty + 1])
            {
                ptr->isLeaf = 1;
                ptr->val = grid[start][starty];
            }
            else
            {
                ptr->isLeaf = 0;
                ptr->topLeft = new Node(grid[start][starty], 1);
                ptr->topRight = new Node(grid[start][starty + 1], 1);
                ptr->bottomLeft = new Node(grid[start + 1][starty], 1);
                ptr->bottomRight = new Node(grid[start + 1][starty + 1], 1);
            }
        }
        else
        {
            int n = size / 2;
            ptr->topLeft = construct(grid, start, starty, n);
            ptr->topRight = construct(grid, start, starty + n, n);
            ptr->bottomLeft = construct(grid, start + n, starty, n);
            ptr->bottomRight = construct(grid, start + n, starty + n, n);
            if (ptr->topLeft->isLeaf && ptr->topRight->isLeaf && ptr->bottomLeft->isLeaf && ptr->bottomRight->isLeaf)
            {
                if (ptr->topLeft->val == ptr->topRight->val && ptr->topLeft->val == ptr->bottomLeft->val && ptr->topLeft->val == ptr->bottomRight->val)
                {
                    ptr->isLeaf = 1;
                    ptr->val = ptr->bottomLeft->val;
                    ptr->topLeft = NULL;
                    ptr->topRight = NULL;
                    ptr->bottomLeft = NULL;
                    ptr->bottomRight = NULL;
                    return ptr;
                }
            }
            ptr->isLeaf = 0;
        }
        return ptr;
    }
};
int main()
{

    return 0;
}