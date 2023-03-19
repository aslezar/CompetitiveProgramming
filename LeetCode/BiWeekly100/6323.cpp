#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
            return -1;
        if (money == children)
            return 0;
        money -= children;
        int t = money / 7;
        int r = money % 7;
        if (t > children)
            return children - 1;
        if (t == children && r == 0)
            return children;
        if (t == children && r != 0)
            return children - 1;
        if (t == children - 1 && r == 3)
            return children - 2;
        if (t == children - 1 && r != 3)
            return children - 1;
        return t;
    }
};
int main()
{

    return 0;
}