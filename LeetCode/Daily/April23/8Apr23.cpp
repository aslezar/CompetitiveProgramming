#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneNode(Node *node, vector<Node *> &v)
    {
        if (!node)
            return nullptr;
        Node *root = new Node(node->val);
        v[root->val] = root;
        for (auto &&i : node->neighbors)
        {
            if (v[i->val] == 0)
                root->neighbors.push_back(cloneNode(i, v));
            else
                root->neighbors.push_back(v[i->val]);
        }
        return root;
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        vector<Node *> v(101, nullptr);
        return cloneNode(node, v);
    }
};
int main()
{
    return 0;
}