#include <iostream>
#include <math.h>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int replace(int num, int a, int b)
    {
        int ans = 0;
        int i = 0;
        cout << "Replace " << num << ' ' << a << ' ' << b << ' ';
        while (num)
        {
            int d = num % 10;
            num /= 10;
            if (d == a)
                d = b;

            ans += d * pow(10, i++);
        }
        cout << ans << '\n';
        return ans;
    }
    int minMaxDifference(int num)
    {
        int max = num, min = num;
        int digit = -1;
        int digits = -1;
        int t = num;
        while (t)
        {
            int temp = t % 10;
            t /= 10;
            if (temp != 9)
                digit = temp;
        }
        cout << digit << '\n';
        if (digit == -1)
            return num;
        max = replace(num, digit, 9);
        t = num;
        while (t)
        {
            digits++;
            t /= 10;
        }
        t = num / pow(10, digits);
        min = replace(num, t, 0);
        cout << max << ' ' << min;
        return max - min;
    }
};
int main()
{

    return 0;
}