#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

int tribonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n == 2)
        return 1;
    int t0 = 0, t1 = 1, t2 = 1;
    for (int i = 0; i < n - 2; i++)
    {
        int temp = t2;
        t2 = temp + t1 + t0;
        t0 = t1;
        t1 = temp;
    }
    return t2;
}
int main()
{
    cout << tribonacci(4) el;
    return 0;
}