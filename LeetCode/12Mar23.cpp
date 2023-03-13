#include <iostream>
#include <vector>
#include <climits>
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
    ListNode *mergeKLists(vector<ListNode *> &lists, int list = 1)
    {
        if (list == lists.size())
            return NULL;
        ListNode *ans;
        ListNode *list1 = lists[0];
        ListNode *list2 = lists[list];
        if (list1->val < list2->val)
        {
            ans = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            ans = new ListNode(list2->val);
            list2 = list2->next;
        }
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                ans->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                ans->next = new ListNode(list2->val);
                list2 = list2->next;
            }
        }
        while (list1 != NULL)
        {
            ans->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            ans->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        return lists[0];
    }
};
int main()
{

    return 0;
}
