#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int j = 0;
        for (auto &&i : pushed)
        {
            s.push(i);
            while (j < pushed.size() && !s.empty() && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }
        return j == pushed.size();
    }
};
int main()
{

    return 0;
}