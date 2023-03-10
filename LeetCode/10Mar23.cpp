#include <iostream>
#include <ctime>
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
    ListNode *head;
    int size;

public:
    Solution(ListNode *headh)
    {
        head = headh;
        int i = 0;
        while (headh != NULL)
        {
            headh = headh->next;
            i++;
        }
        size = i;
        srand((unsigned)time(0));
    }

    int getRandom()
    {
        int no = (rand() % size) + 1;
        ListNode *temp = head;
        while (no--)
        {
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{

    return 0;
}