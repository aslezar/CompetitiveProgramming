#include <iostream>
#include <set>
using namespace std;

#define el << '\n'
#define ws << ' '

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *slow = head, *fast = head, *curr = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                while (slow != curr)
                {
                    slow = slow->next;
                    curr = curr->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
class Solution2
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> ptr;
        ListNode *temp = head;
        while (temp != NULL)
        {
            auto it = ptr.find(temp);
            if (it != ptr.end())
                return *it;
            ptr.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};
int main()
{

    return 0;
}