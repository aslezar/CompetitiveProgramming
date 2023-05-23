#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

class KthLargest
{
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> no;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto &&i : nums)
        {
            no.push(i);
            if (no.size() > k)
                no.pop();
        }
    }

    int add(int val)
    {
        no.push(val);
        while (no.size() > k)
            no.pop();
        return no.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{

    return 0;
}