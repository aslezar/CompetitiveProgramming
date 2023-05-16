#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<int> v;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int swap = v[k - 1];
        v[k - 1] = v[v.size() - k];
        v[v.size() - k] = swap;
        ListNode *head2 = new ListNode(v[0]);
        temp = head2;
        for (int i = 1; i < v.size(); i++)
        {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head2;
    }
};
int main()
{

    return 0;
}