#include <iostream>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

int divide(int dividend, int divisor)
{
    bool isPositive = (dividend < 0 == divisor < 0);
    cout << isPositive;
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0;
    if (a < b)
        return 0;
    if (a == b)
        return isPositive ? 1 : -1;
    while (a >= b)
    {
        short q = 0;
        while (a > (b << (q + 1)))
            q++;
        ans += (1 << q);
        a -= (b << q);
    }
    if (ans == (1 << 31) && isPositive)
        return INT_MAX;
    return isPositive ? ans : -ans;
}

int main()
{
    cout << divide(10, 3);
    return 0;
}